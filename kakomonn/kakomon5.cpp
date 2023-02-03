
#include <iostream>
using namespace std;
#define n 1000
int top = 0, sum = 0, A[n];

void push (int x){
    top++;
    A[top] = x;
}

int pop(void){
    top--;
    if(top < 0) return -1;
    return A[top+1];
}

int main(){
    int x,y,z;
    for(int i = 0; i < n; i++){
        cin >> y;
        if(y > 0)  push(y);
        else  pop();
    }

    for(int j = 0; j < n; j++){
        x = pop();
        if(x != -1 )sum += x;
        else break;
    }

    cout << sum << endl;
    return 0;
}
