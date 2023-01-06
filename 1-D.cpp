#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int A[N];
    int i;
    for(i = 0; i < N; ++i) cin >> A[i];
    
    int minv, maxp;
    minv = A[0];
    maxp = A[1] - A[0];

    for(i = 1; i < N; ++i) {
        maxp = max(maxp, A[i] - minv);
        minv = min(minv, A[i]);
    }

    cout << maxp << endl;
    return 0;
}