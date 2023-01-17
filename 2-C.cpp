#include<iostream>
using namespace std;

struct Card {
    char suit;
    char value;
};

void bubble(Card A[], int N) {
    bool key = true;
    for(int i = 0; key; ++i) {
        key = false;
        for(int j = N - 1; j >= i; --j) {
            if(A[j].value < A[j - 1].value) {
                swap(A[j], A[j - 1]);
                key = true;
            }
        }
    }
}

void select(Card A[], int N) {
    int minj;
    for(int i = 0; i < N - 1; ++i) {
        minj = i;
        for(int j = i; j < N; ++j) {
            if(A[j].value < A[minj].value) minj = j;
        }
        swap(A[i], A[minj]);
    }
}

bool isStable(Card C1[], Card C2[], int N) {
    for(int i = 0; i < N; i++) {
        if(C1[i].suit != C2[i].suit) return false;
    }
    return true;
}


int main() {
    Card C1[100], C2[100];
    int N;

    cin >> N;
    for(int i; i < N; i++) {
        cin >> C1[i].suit >> C1[i].value;
    }

    for(int i; i < N; i++) C2[i] = C1[i];

    bubble(C1, N);
    select(C2, N);

    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << C1[i].suit << C1[i].value;
    }
    cout << endl;
    cout << "Stable" << endl;
    for(int i = 0; i < N; i++) {
        if(i) cout << " ";
        cout << C2[i].suit << C2[i].value;
    }
    cout << endl;
    
    if(isStable(C1, C2, N)) cout << "Stable" << endl;
    else cout << "Not stable" << endl;

    return 0;
}
