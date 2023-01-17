#include<iostream>
using namespace std;
#define MAX 100001

int main() {
    int N;
    int A[MAX];

    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = 1; i <= N; i++) {
        cout << "node " << i << ": key = " << A[i] << ", ";
        if(i != 1) cout << "parent key = " << A[i / 2] << ", ";
        if(i * 2 <= N) cout << "left key = " << A[i * 2] << ", ";
        if((i * 2) + 1 <= N ) cout << "right key = " << A[(i * 2) + 1] << ", ";
        cout << endl;
    }

    return 0;
}