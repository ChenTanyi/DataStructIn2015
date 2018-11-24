#include <iostream>
#include "Headers/function.h"
#include "Headers/Exercise2.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>

int main(){
    srand(time(0));
    exBST<int, int, Identity<int>, less<int> > exbst;
    for (int i = 0 ; i < 10 ; ++ i){
        int x = rand()%1000;
        std :: cout << x << " ";
        exbst.insert(x);
        exbst.insert(x);
    }
    std :: cout << "\n";
    for (exBST<int, int, Identity<int>, less<int> >::iterator it = exbst.begin() ; it != exbst.end() ; ++ it){
        std :: cout << *it << " ";
    }
    std :: cout << "\n\n";
    exbst.eraseGreater(800);
    for (exBST<int, int, Identity<int>, less<int> >::iterator it = exbst.begin() ; it != exbst.end() ; ++ it){
        std :: cout << *it << " ";
    }
    std :: cout << "\n\n";
    exbst.eraseLess(200);
    for (exBST<int, int, Identity<int>, less<int> >::iterator it = exbst.begin() ; it != exbst.end() ; ++ it){
        std :: cout << *it << " ";
    }
    std :: cout << "\n\n";
    exbst.eraseRange(400,600);
    for (exBST<int, int, Identity<int>, less<int> >::iterator it = exbst.begin() ; it != exbst.end() ; ++ it){
        std :: cout << *it << " ";
    }
    std :: cout << "\n";
    return 0;
}
