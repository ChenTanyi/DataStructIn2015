#include <iostream>
#include "../Headers/HuffmanTree.h"

void huffmanCoding(HuffNode<char>* parent, const HuffCode & code, HuffCodeMap & result){
    if (parent->leaf()){
        result.push_back(pair<char, HuffCode>(parent->value(),code));
    }
    else {
        HuffCode leftcode = code;
        leftcode.push_back(0);
        huffmanCoding(parent->left(), leftcode, result);

        HuffCode rightcode = code;
        rightcode.push_back(1);
        huffmanCoding(parent->right(), rightcode, result);
    }
}

void huffmanEncode(HuffSource text, HuffTree<char>* & tree, HuffCodeMap & result){
    int times[222];
    std :: fill (times, times + 200, 0);
    for (int i = 0 ; i < text.size() ; ++ i){
        ++times[text[i]];
    }
    vector<HuffTree<char>*> v;
    for (char i = 0 ; i >= 0 ; ++ i){
        if (times[i])
            v.push_back(new HuffTree<char>(i,times[i]));
    }
    tree = HuffTree<char>::build(v);
    huffmanCoding(tree->root(), HuffCode(), result);
}
