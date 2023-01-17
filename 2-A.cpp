#include<iostream>
using namespace std;

int bubble(int A[], int N) {
    int count = 0;
    bool key = true;
    for(int i = 0; key; ++i) {
        key = false;
        for(int j = N - 1; j > i; --j) {
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                key = true;
                ++count;
            }
        }
    }
    return count;
}


int main() {
    int N, count;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; ++i) cin >> A[i];
    count = bubble(A, N);
    for(int i = 0; i < N; ++i) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}