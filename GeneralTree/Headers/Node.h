#ifndef Node_H
#define Node_H

class Node{
private:
    char nodeValue;
    Node* parentNode;
    Node* leftNode;
    Node* rightNode;
public:
    Node(char v, Node* p = 0, Node* l = 0, Node* r = 0);
    char & value();
    const char & value() const;
    Node * & parent();
    void setParent(Node*);
    Node * & left();
    void setLeft(Node*);
    Node * & right();
    void setRight(Node*);
};

#endif // Node_H
