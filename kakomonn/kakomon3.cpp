
#include <iostream>
using namespace std; 
#define N 1000001

int main(){
    int cnt = 0, tmp;
    int A[N];

    for(int i = 0; i < N; i++) cin >> A[i];

    for(int k = 0; k<  N; k++) {
        for(int j = N - 1; j >= k + 1; j--) {
            if(A[j] < A[j-1]){
                tmp = A[j-1];
                A[j-1] = A[j];
                A[j]=tmp;
                cnt++;
        }
        }
    }

    for(int l = 0; l < N; l++){
        cout << A[l];
        if(l != N - 1) cout << " ";
        else cout << endl;
    }

    
    int i = 0;
    for(i = 0; i < (N - 1) / 2; i++) 
    cout << A[i] << endl;

    return 0;
}
