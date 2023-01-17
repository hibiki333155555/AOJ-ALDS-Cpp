#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int parent, left, right; };

Node T[MAX];
int N, D[MAX], H[MAX];

int GetSibling(int u) {
    if(T[u].parent == NIL) return NIL;
    if(T[T[u].parent].right != NIL && T[T[u].parent].left == u) {
        return T[T[u].parent].right;
    }
    if(T[T[u].parent].left != NIL && T[T[u].parent].right == u) {
        return T[T[u].parent].left;
    }
    return NIL;
}

void PrintAll(int u) {
    cout << "node " << u << ": ";
    cout << "parent = " << T[u].parent << ", ";
    cout << "sibling = " << GetSibling(u) << ", ";

    int deg = 0;
    if(T[u].left != NIL) ++deg;
    if(T[u].right != NIL) ++ deg;

    cout << "degree = " << deg << ", ";
    cout << "depth = " << D[u] << ", ";
    cout << "height = " << H[u] << ", ";
    
    if(T[u].parent == NIL) cout << "root";
    else if(T[u].left == NIL && T[u].right == NIL) cout << "leaf";
    else cout << "internal node";

    cout << endl;
}

void SetDepth(int u, int dep) {
    D[u] = dep;
    if(T[u].left != NIL) SetDepth(T[u].left, dep + 1);
    if(T[u].right != NIL) SetDepth(T[u].right, dep + 1);
}

int SetHeight(int u) {
    int hleft = 0, hright = 0;
    if(T[u].left != NIL) {
        hleft = SetHeight(T[u].left)+ 1;
    }
    if(T[u].right != NIL) {
        hright = SetHeight(T[u].right) + 1;
    }
    return H[u] = (hleft > hright ? hleft : hright);
}

int main() {
    int number, nchild, l, r, k, root;
    cin >> N;
    for(int i = 0; i < N; ++i)  T[i].parent = T[i].left = T[i].right = NIL;
    
    for(int i = 0; i < N; ++i) {
        cin >> number >> l >> r;
        T[number].left = l;
        T[number].right = r;
        if(l != NIL) T[l].parent = number;
        if(r != NIL) T[r].parent = number;
    }

    for(int i = 0; i < N; ++i) {
        if(T[i].parent == NIL) root = i;
    }

    SetDepth(root, 0);
    SetHeight(root);

    for(int i = 0; i < N; ++i) PrintAll(i);

    return 0;
}