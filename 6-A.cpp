#include <iostream>
#include <algorithm>
#define S 2000000
#define K 10001
using namespace std;
int A[S];
int B[S] = { 0 };


void CountingSort(int N) {
    int C[K] = { 0 };
    for(int j = 0; j < N; ++j) ++C[A[j]];
    for(int i = 1; i < K; ++i) C[i] += C[i - 1];
    for(int j = N; j >= 0; --j) {
        B[C[A[j]] - 1] = A[j];
        --C[A[j]];
    }
}

int main() {
    int N; 
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];
    CountingSort(N);
    for(int i = 0; i < N; ++i) {
        if(i) cout << ' ';
        cout << B[i];
    }
    cout << endl;
    return 0;
}