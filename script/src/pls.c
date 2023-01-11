#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <curl/curl.h>
#include "json.h"

/* holder for curl fetch */
struct curl_fetch_st {
    char *payload;
    size_t size;
};

/* callback for curl fetch */
size_t curl_callback (void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;                             /* calculate buffer size */
    struct curl_fetch_st *p = (struct curl_fetch_st *) userp;   /* cast pointer to fetch struct */

    /* expand buffer using a temporary pointer to avoid memory leaks */
    char * temp = realloc(p->payload, p->size + realsize + 1);

    /* check allocation */
    if (temp == NULL) {
      /* this isn't good */
      fprintf(stderr, "ERROR: Failed to expand buffer in curl_callback");
      /* free buffer */
      free(p->payload);
      /* return */
      return 1;
    }

    /* assign payload */
    p->payload = temp;

    /* copy contents to buffer */
    memcpy(&(p->payload[p->size]), contents, realsize);

    /* set new buffer size */
    p->size += realsize;

    /* ensure null termination */
    p->payload[p->size] = 0;

    /* return size */
    return realsize;
}

/* fetch and return url body via curl */
CURLcode curl_fetch_url(CURL *ch, const char *url, struct curl_fetch_st *fetch) {
    CURLcode res;

    /* init curl handle */
    if ((ch = curl_easy_init()) == NULL) {
        /* log error */
        fprintf(stderr, "ERROR: Failed to create curl handle in fetch_session");
        /* return error */
        return 1;
    }

    /* init payload */
    fetch->payload = (char *) calloc(1, sizeof(fetch->payload));

    /* check payload */
    if (fetch->payload == NULL) {
        /* log error */
        fprintf(stderr, "ERROR: Failed to allocate payload in curl_fetch_url");
        /* return error */
        return CURLE_FAILED_INIT;
    }

    /* init size */
    fetch->size = 0;

    curl_easy_setopt(ch, CURLOPT_URL, url);

    /* set calback function */
    curl_easy_setopt(ch, CURLOPT_WRITEFUNCTION, curl_callback);

    /* pass fetch struct pointer */
    curl_easy_setopt(ch, CURLOPT_WRITEDATA, (void *) fetch);

    /* set default user agent */
    curl_easy_setopt(ch, CURLOPT_USERAGENT, "libcurl-agent/1.0");

    /* set timeout */
    curl_easy_setopt(ch, CURLOPT_TIMEOUT, 15);

    /* enable location redirects */
    curl_easy_setopt(ch, CURLOPT_FOLLOWLOCATION, 1);

    /* set maximum allowed redirects */
    curl_easy_setopt(ch, CURLOPT_MAXREDIRS, 1);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(ch);

    /* Check for errors */
    if(res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
    }
    /* always cleanup */
    curl_easy_cleanup(ch);

    /* return */
    return res;
}

typedef struct {
    char id[64], name[256];
    double score;
} Problem;

typedef struct {
    Problem *items;
    size_t size;
} Problems;

Problems parse_problems(struct json_value_s *json) {
    struct json_object_s* object = json_value_as_object(json);
    struct json_object_element_s* curr = object->start;
    struct json_array_s* problems_arr;
    while (curr != NULL) {
        if (strcmp(curr->name->string, "problems") == 0) {
            problems_arr = (struct json_array_s*)curr->value->payload;
        }
        curr = curr->next;
    }
    
    Problems problems = { malloc(problems_arr->length * sizeof(Problem)), problems_arr->length };
    struct json_array_element_s* b = problems_arr->start;

    for (size_t i = 0; i < problems.size; i++,b=b->next) {
        struct json_object_s* item = json_value_as_object(b->value);
        curr = item->start;
        while (curr != NULL) {
            if (strcmp(curr->name->string, "id") == 0) {
                struct json_string_s* id = (struct json_string_s*)curr->value->payload;
                strcpy(problems.items[i].id, id->string);
            } else if (strcmp(curr->name->string, "name") == 0) {
                struct json_string_s* name = (struct json_string_s*)curr->value->payload;
                strcpy(problems.items[i].name, name->string);
            } else if (strcmp(curr->name->string, "score") == 0) {
                struct json_string_s* score = (struct json_string_s*)curr->value->payload;
                problems.items[i].score = atof(score->string);
            }
            curr = curr->next;
        }
    }
    return problems;
}

int cmpfunc (const void * a, const void * b) {
    double s1 = ((Problem*)a)->score;
    double s2 = ((Problem*)b)->score;
    return  s1 < s2 ? 1 : s1 > s2 ? -1 : strcmp(((Problem*)a)->id, ((Problem*)b)->id);
}

void get_problem_list(char *listing) {
    CURL *ch = NULL;
    // CURLcode res;
    struct curl_fetch_st fetch;
    char url[150] = "https://judgeapi.u-aizu.ac.jp/problems/";
    strcat(url, listing);

    curl_fetch_url(ch, url, &fetch);

    struct json_value_s *json;
    /* check payload */
    if (fetch.payload != NULL) {
        /* print result */
        // printf("CURL Returned: \n%s\n", fetch.payload);
        /* parse return */
        json = json_parse(fetch.payload, fetch.size);
        /* free payload */
        free(fetch.payload);

        Problems problems = parse_problems(json);
        qsort(problems.items, problems.size, sizeof(Problem), cmpfunc);
        for (size_t i = 0; i < problems.size; i++) {
            printf("%lf\t%s\t%s\n", problems.items[i].score, problems.items[i].id, problems.items[i].name);
        }
        free(problems.items);
    } else {
        /* error */
        fprintf(stderr, "ERROR: Failed to populate payload");
        /* free payload */
        free(fetch.payload);
        /* return */
        exit(1);
    }

    // /* free json object before return */
    free(json);
}

int main(int argc, char *argv[]) {
    get_problem_list(argv[1]);
    return 0;
}