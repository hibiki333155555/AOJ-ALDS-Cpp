// フィボナッチ数列のDPによる実装
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int F[N + 1];

    F[0] = 1;
    F[1] = 1;

    for(int i = 2; i <= N; i++) F[i] = F[i - 1] + F[i - 2];

    cout << F[N] << endl;
    return 0;
}