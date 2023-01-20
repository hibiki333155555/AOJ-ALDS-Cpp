#include <iostream>
using namespace std;
#define MAX 1000000000

int main() {
    int p[101], m[101][101];

    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> p[i - 1] >> p[i];

    for(int i = 1; i <= N; i++) m[i][i] = 0;

    // l = 組み合わせる行列の数
    for(int l = 2; l <= N; l++) {

        // i = 組み合わせる行列のうち先頭の行列の番号　M1M2　の組なら　i = 1 
        for(int i = 1; i <= N - l + 1; i++) {
            // j = 組み合わせる行列のうち最後の行列の番号　M1M2M3　の組なら　j = 3 
            int j = i + l - 1;
            m[i][j] = MAX;
            // k はどの位置で行列を分けるかを示す
            for(int k = i; k <= j; k++) {
                m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
            }
        }
    }

    cout << m[1][N] << endl;
    return 0;
}