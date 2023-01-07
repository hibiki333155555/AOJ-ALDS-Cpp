#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

int Pre[MAX], In[MAX], Post[MAX];
int N;
int pos = 0;
int idx = 0;

void ReconstPost(int left, int right){
    if(left >= right) return ;
    int root = Pre[pos++];
    int key;
    for(int i = left; i < right; ++i) {
        if(root == In[i]) key = i;
    }
    ReconstPost(left, key);
    ReconstPost(key + 1, right);
    Post[idx++] = root;
}

void PrintPost() {
    ReconstPost(0, N);
    for(int i = 0; i < N; ++i) {
        if(i) cout << " ";
        cout << Post[i];
    }
    cout << endl;
}

int main() {
    int k;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> Pre[i];
    
    for(int i = 0; i < N; ++i) cin >> In[i];

    PrintPost();

    return 0;
}
