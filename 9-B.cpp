#include<iostream>
using namespace std;
#define MAX 500000

void maxHeapify(int A[], int k, int N) {

    int l = k * 2;
    int r = (k * 2) + 1;
    int largest;

    // max((left, parent), right)
    if(l <= N && A[l] > A[k]) largest = l;
    else largest = k;
    if (r <= N && A[r] > A[largest]) largest = r;

    // largest が　A[k] の移動先の添字であることに注意
    if(largest != k) {
        swap(A[k], A[largest]);
        maxHeapify(A, largest, N);
    }
}

int main() {
    int N;
    int A[MAX];
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    for(int i = N / 2; i >= 1; i--) maxHeapify(A, i, N);

    for(int i = 1; i <= N; i++) cout << " " << A[i];

    cout << endl;
    return 0;
}