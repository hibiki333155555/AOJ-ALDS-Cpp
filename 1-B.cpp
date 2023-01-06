#include<iostream>
using namespace std;
int gcd(int x, int y) {
    int r;
    while(y > 0) {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
int main() {
    int x, y;
    cin >> x >> y;
    if(x<y) swap(x, y);
    cout << gcd(x, y) << endl;
    return 0;
}