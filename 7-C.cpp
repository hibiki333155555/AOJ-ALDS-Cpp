#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node { int parent, left, right; };

Node T[MAX];
int N;

//root -> left -> right
void PreOrder(int u) {
    if(u == NIL) return;
    cout << " " << u;
    PreOrder(T[u].left);
    PreOrder(T[u].right);
}

//left -> root -> right
void InOrder(int u) {
    if(u == NIL) return;
    InOrder(T[u].left);
    cout << " " << u;
    InOrder(T[u].right);
}

//left -> right -> root
void PostOrder(int u) {
    if(u == NIL) return;
    PostOrder(T[u].left);
    PostOrder(T[u].right);
    cout << " " << u;
}

void PrintAll(int u) {
    cout << "Preorder" << endl;
    PreOrder(u);
    cout << endl;

    cout << "Inorder" << endl;
    InOrder(u);
    cout << endl;

    cout << "Postorder" << endl;
    PostOrder(u);
    cout << endl;
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

    PrintAll(root);

    return 0;
}