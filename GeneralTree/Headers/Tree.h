#ifndef Tree_H
#define Tree_H

#include "Node.h"

class Tree{
private:
    Node* rootNode;//���ڵ�
    int generalFlag;//�ж�Ϊ������������ͨ����
    void toBinary(Node*, Node*);//��ͨ��ת������
    void toGeneral(Node*, Node*);//������ת��ͨ��
    void preorder(Node*);//ǰ�����
    void inorder(Node*);//������������޶�����
    void destroy(Node*);//ɾ����
    void build(char* &, Node*, Node*, Node* &, int &);//����
public:
    Tree();
    ~Tree();
    void preorder();//ǰ�����
    void inorder();//������������޶�����
    Node* root();
    void setRoot(Node*);
    void merge(Tree &);//���������ϲ�
    bool build(char* &);//����
    void generalToBinary();//��ͨ��ת������
    void binaryToGeneral();//������ת��ͨ��
};

#endif // tree_H
