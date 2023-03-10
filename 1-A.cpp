#include <iostream>
using namespace std;

void printarray(int A[], int n){
    int i;
    for(i = 0; i < n; i++) {
        cout << A[i];
        if(i + 1 < n) cout << " ";
    }
    cout << endl;
}


int main() {
    int n, i, j, key;
    int A[100];
    
    cin >> n;
    for(i = 0; i < n; i++) cin >> A[i];
    
    printarray(A, n);
    
    for(i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        printarray(A, n);
    }
    
    return 0;
}
