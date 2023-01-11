#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

//自己参照構造体の定義 
//メンバに持つのは構造体(Node)ではなく、構造体を参照するポインタであることに注意
//↓のような構造体(Node)の宣言はできないことに注意
// struct Node{
//     int key;
//☆    Node right, left, parent;
// };

struct Node{
    int key;
    Node *right, *left, *parent;
};

//全てのNode型変数はポインタとして宣言しないと他のNode型変数から参照できない
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
    else if(operation == "print") {
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
    }
  }


  return 0;
}
