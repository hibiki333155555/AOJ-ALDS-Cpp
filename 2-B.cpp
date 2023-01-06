#include <iostream>
using namespace std;

int main() {
    int A[100], N;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];
    
    int count = 0, minj;

    for(int i = 0; i < N - 1; ++i) {
        minj = i;
        for(int j = i; j < N; ++j) {
            if(A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
        if(i != minj)count++;
    }
    
    for(int i = 0; i < N; ++i) {
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}

