#include <iostream>
using namespace std;


int linerSearch(int A[], int key, int N) {
    int i = 0;
    A[N] = key;
    while(key != A[i]) i++;
    if(i == N) return -1;
    return i;
}

int main() {
    int N, Q;

    cin >> N;
    int S[N];
    for(int i = 0; i < N; i++) cin >> S[i];
    cin >> Q;
    int T[Q];
    for(int i = 0; i < Q; i++) cin >> T[i];

    int count = 0;
    for(int i = 0; i < Q; i++) {
        if(linerSearch(S, T[i], N) != -1) count++;
    }

    cout << count << endl;
    return 0;
}