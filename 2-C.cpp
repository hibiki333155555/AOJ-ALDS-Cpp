#include<iostream>
using namespace std;

void bubble(int A[], int N) {
    bool key = true;
    for(int i = 0; key; ++i) {
        key = false;
        for(int j = N - 1; j >= i; --j) {
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                key = true;
            }
        }
    }
}

void select(int A[], int N) {
    int minj;
    for(int i = 0; i < N - 1; ++i) {
        minj = i;
        for(int j = i; j < N; ++j) {
            if(A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
    }
}
