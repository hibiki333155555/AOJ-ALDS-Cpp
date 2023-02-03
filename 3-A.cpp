#include <iostream>
#include <string>
using namespace std;
#define MAX 1000
int top = 0;
int S[MAX];

int pop() {
    top--;
    return S[top + 1];
}

void push(int x) {
    S[++top] = x;
}

int main() {
    string operation;


    while(cin >> operation) {
        if(operation == "+") push(pop() + pop());
        else if(operation == "-") push(pop() - pop());
        else if(operation == "*") push(pop() * pop());
        else push(stoi(operation));
    }

    cout << pop() << endl;
    return 0;
}