/*二つの数列で同じ数の個数を数える。*/
#include <iostream>
using namespace std;

#define n 10


int linesearch(int *c,int key){
    int i = 0;
    c[n] = key;
    while(c[i] != key){
        i++;
    }
    if(i == n) return 0;
    return 1;
}

int main(){
    int q,cnt=0;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    int b[n];
    for(int i = 0; i < n; i++) cin >> b[i];

    for(int l=0;l<n;l++)cnt+=linesearch(b,a[l]);
        
    cout << cnt << endl;

    return 0;
}
