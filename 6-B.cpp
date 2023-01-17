#include <iostream>
#include <algorithm>
using namespace std;

int A[100000];

int partition(int p, int r) {
    int x = A[r];
    int i = p - 1;
    
    for(int j = p; j < r; ++j) {
        if(A[j] <= x) {
            ++i;
            swap(A[j], A[i]);
        }
    }
    
    swap(A[i+1], A[r]);
    return i + 1;
}


int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];
    
    int point = partition(0, N - 1);

    for(int i = 0; i < N; ++i) {
        if(i) cout << ' ';
        if(i == point) cout << '[';
        cout << A[i];
        if(i == point) cout << ']';
    }

    cout << endl;
    return 0;
}