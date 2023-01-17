#include <iostream>
#include <math.h>
using namespace std;

int isPrime(int x) {
    int i;
    if(x == 2) return true;
    if(x < 2 || x % 2 == 0) return false;

    i = 3;
    while(i <= sqrt(x)){ 
        if(x % i == 0) return false;
        i = i + 2;
    }

    return true;
}


int main() {
    int N;
    cin >> N;
    int A[N];
    int count = 0;
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) {
        if(isPrime(A[i])) ++count;
    }
    cout << count << endl;
}