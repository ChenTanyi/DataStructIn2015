#ifndef Tree_H
#define Tree_H

#include "Node.h"

class Tree{
private:
    Node* rootNode;//根节点
    int generalFlag;//判断为二叉树还是普通的树
    void toBinary(Node*, Node*);//普通树转二叉树
    void toGeneral(Node*, Node*);//二叉树转普通树
    void preorder(Node*);//前序遍历
    void inorder(Node*);//中序遍历，仅限二叉树
    void destroy(Node*);//删除树
    void build(char* &, Node*, Node*, Node* &, int &);//建树
public:
    Tree();
    ~Tree();
    void preorder();//前序遍历
    void inorder();//中序遍历，仅限二叉树
    Node* root();
    void setRoot(Node*);
    void merge(Tree &);//将两棵树合并
    bool build(char* &);//建树
    void generalToBinary();//普通树转二叉树
    void binaryToGeneral();//二叉树转普通树
};

#endif // tree_H
