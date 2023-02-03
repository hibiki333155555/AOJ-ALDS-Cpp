//8-Bにdeleteの実装を加える
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

struct Node{
    int key;
    Node *right, *left, *parent;
};

Node *root, *NIL;

void insert(int d){
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = (Node *)malloc(sizeof(Node));
    z->key = d;
    z->left = NIL;
    z->right = NIL;

    while(x != NIL) {
        y = x;
        if(z->key < x->key) x = x->left;
        else if(z->key > x->key) x = x->right;
    }
    
    z->parent == y;

    if(y == NIL) root = z;
    else {
        if(z->key < y->key) y->left = z;
        else y->right = z; 
    }
}

void find(Node *u, int k) {
    while(u != NIL && k != u->key) {
        if(u->key < k) u = u->right;
        else u = u->left;
    }
    if(u == NIL) cout << "no" << endl;
    else cout << "yes" << endl;
}

void dele(Node *u, int k) {
    while(k != u->key) {
        if(u->key < k) u = u->right;
        else u = u->left;
    }

    if(u->left == NIL && u->right == NIL) u = NIL;
    else if(u);
}

void inorder(Node *u){
    if(u == NIL) return;
    inorder(u->left);
    cout << " " << u->key;
    inorder(u->right);
}

void preorder(Node *u){
    if(u == NIL) return;
    cout << " " << u->key;
    preorder(u->left);
    preorder(u->right);
}


int main(){
  string operation;
  int N;
  cin >> N;
  int k;


  for (int i = 0; i < N; i++){
    cin >> operation;
    if(operation == "insert") {
        cin >> k;
        insert(k);
    }
    else if(operation == "find") {
        cin >> k;
        find(root, k);
    }
    else if(operation == "delete") {
        cin >> k;
        dele(root, k);
    }
    else if(operation == "print") {
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
    }
  }
  return 0;
}
