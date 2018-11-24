#include <iostream>
#include "../Headers/HuffmanTree.h"

bool huffmanDecode(const HuffCode & code, HuffTree<char>* tree, HuffSource & result){
    HuffNode<char>* p = tree -> root();
    for (int i = 0 ; i < code.size(); ++ i){
        if (p->leaf()){
            result.push_back(p->value());
            p = tree -> root();
            -- i;
        }
        else if (code[i])
            p = p -> right();
        else p = p -> left();
    }
    if (!p -> leaf()) return 0;
    else {
        result.push_back(p->value());
        return 1;
    }
}
