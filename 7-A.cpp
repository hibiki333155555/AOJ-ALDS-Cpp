// 木構造の実装

#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

//　構造体によるノードの実装
struct Node { int parent, left, right; };

// T[u] にはノード番号 u に対して親と子のノード番号が格納されている
Node T[MAX];

int N, D[MAX];

void PrintChild(int u) {
    int c = T[u].left;
    cout << "[";
    for(int i = 0; c != NIL; ++i, c = T[c].right) {
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]";
}

void PrintAll(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "depth = " << D[u] << ", ";
    
    if(T[u].parent == NIL) cout << "root, ";
    else if(T[u].left == NIL) cout << "leaf, ";
    else cout << "internal node, ";

    PrintChild(u);
    cout << endl;
}

// 再帰関数で D[u] に全てのノード u の深さを代入する
void SetDepth(int u, int dep) {
    D[u] = dep;
    if(T[u].right != NIL) SetDepth(T[u].right, dep);
    if(T[u].left != NIL) SetDepth(T[u].left, dep + 1);
}

int main() {
    int number, nchild, ch, k, root;
    cin >> N;
    for(int i = 0; i < N; ++i)  T[i].parent = T[i].left = T[i].right = NIL;
    
    for(int i = 0; i < N; ++i) {
        cin >> number >> nchild;
        for(int j = 0; j < nchild; ++j) {
            cin >> ch;
            if(j == 0) T[number].left = ch;
            else T[k].right = ch;
            k = ch;
            T[ch].parent = number;
        }
    }

    for(int i = 0; i < N; ++i) {
        if(T[i].parent == NIL) root = i;
    }

    SetDepth(root, 0);

    for(int i = 0; i < N; ++i) PrintAll(i);

    return 0;
}