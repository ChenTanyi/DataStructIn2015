#include "../Headers/Tree.h"
#include <iostream>
#include <cstdio>

const int N = 1e5+10;

char buffer[N];

int main(){
    std :: cout << "Please enter your tree file path: ";
    gets(buffer);
    freopen(buffer,"r",stdin);
    gets(buffer);
    char* s = buffer;
    Tree tree;
    if (!tree.build(s)){
        std :: cout << "Construction was error!\n";
        return -1;
    }
    tree.generalToBinary();
    tree.inorder();
    return 0;
}
