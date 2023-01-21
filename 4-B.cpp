#include <iostream>
using namespace std;
#define MAX 100000

bool binarySearch(int A[], int key, int N) {

    int left = 0;
    int right = N;
    int mid;

    while(left < right) {
        mid = (left + right) / 2;

        if(A[mid] == key) return true; 
        else if(A[mid] > key) right = mid;
        else left = mid + 1;
    }
    return false;
}

int main() {
    int N, M, A[MAX], count = 0;

    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    cin >> M;
    for(int i = 0; i < M; i++) {
        int key;
        cin >> key;
        if(binarySearch(A, key, N)) count++;
    }

    cout << count << endl;
    return 0;
}

// 5
// 1 2 3 4 5
// 3
// 3 4 1