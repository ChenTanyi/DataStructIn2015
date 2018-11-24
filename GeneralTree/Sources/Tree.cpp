#include "../Headers/Tree.h"
#include <iostream>

Tree::Tree():rootNode(0){}

Tree::~Tree(){destroy(rootNode);}

void Tree::destroy(Node* p){
    if (!p) return;
    destroy(p->left());
    destroy(p->right());
    delete p;
}

Node* Tree::root(){return rootNode;}

void Tree::setRoot(Node* r){rootNode = r;}

void Tree::preorder(){preorder(root());}

void Tree::inorder(){if (!generalFlag) inorder(root());}

bool Tree::build(char* & s){
    Node* head;
    int flag = 0;
    if (*s == ')') return 0;
    head = new Node(*s);
    build(++s, head, head, head -> left() , flag);
    if (!flag) {
        destroy(head);
        return 0;
    }
    else {
        generalFlag = 1;
        rootNode = head;
        return 1;
    }
}

void Tree::build(char* & s, Node* r, Node* parent, Node * & p, int & flag){
    if (!*s){
        flag = 0;
        return;
    }
    if (*s == ')'){
        if (p && r == p -> parent() && *(s+1) == 0)
            flag = 1;
        return;
    }
    p = new Node(*s, parent);
    build(++s, r, p, p -> left(), flag);
    build(++s, r, parent, p -> right(), flag);
    if (p && r == p -> parent() && *s == ')' && !*(s+1))
        flag = 1;
}

void Tree::preorder(Node* p){
    if (!p) return;
    std :: cout << p -> value() << " ";
    preorder(p->left());
    preorder(p->right());
}

void Tree::inorder(Node* p){
    if (!p) return;
    inorder(p -> left());
    std :: cout << p -> value() << " ";
    inorder(p -> right());
}

void Tree::generalToBinary(){
    if (!generalFlag) return;
    toBinary(root()->left(), root());
    generalFlag = 0;
}

void Tree::toBinary(Node* child, Node* parent){
    if (!child) return;
    child -> parent() = parent;
    toBinary(child -> left(), child);
    toBinary(child -> right(), child);
}

void Tree::binaryToGeneral(){
    if (generalFlag) return;
    toGeneral(root() -> left(), root());
    generalFlag = 1;
}

void Tree::toGeneral(Node* child, Node* parent){
    if (!child) return;
    child -> parent() = parent;
    toGeneral(child -> left(), child);
    toGeneral(child -> right(), parent);
}

void Tree::merge(Tree & a){
    if (!root()){
        setRoot(a.root());
        a.setRoot(0);
        return;
    }
    if (!a.root()) return;
    a.root()->right() = root()->left();
    a.root()->parent() = root();
    root()->left() = a.root();
    a.setRoot(0);
}
