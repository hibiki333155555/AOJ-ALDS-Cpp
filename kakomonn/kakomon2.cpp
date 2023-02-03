
#include <iostream>
using namespace std; 
#define N 1000

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

    /*3番目に大きい数まで出力*/
    for(int l = N - 1; l > N - 4; l--) cout << A[l] << endl;
    return 0;
}