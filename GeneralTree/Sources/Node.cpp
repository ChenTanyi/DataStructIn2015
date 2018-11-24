#include "../Headers/Node.h"

Node::Node(char v, Node* p, Node* l, Node* r)
    :nodeValue(v), parentNode(p), leftNode(l), rightNode(r){};

char & Node::value(){
    return nodeValue;
}

const char & Node::value() const{
    return nodeValue;
}

Node * & Node::parent(){
    return parentNode;
}

void Node::setParent(Node * p){
    parentNode = p;
}

Node * & Node::left(){
    return leftNode;
}

void Node::setLeft(Node * l){
    leftNode = l;
}

Node * & Node::right(){
    return rightNode;
}

void Node::setRight(Node * r){
    rightNode = r;
}
