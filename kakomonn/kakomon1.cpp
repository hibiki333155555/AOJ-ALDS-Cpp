
#include <iostream>
using namespace std; 
#define N 30000

int main(){
        
    int cnt = 0, A[N];

    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] % 2 != 0) cnt++;
    }

    cout << cnt << endl;
    return 0;
}