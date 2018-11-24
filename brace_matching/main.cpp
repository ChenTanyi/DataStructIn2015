#include "stack.h"
#include <fstream>

int main(){
    std :: ifstream fin("test.in");// ----------------------------use counter to solve
    char c;
    int total = 0;
    for (; fin >> c ; ){
        if (c == '(') ++ total;
        else if (c == ')') -- total;
        if (total < 0)
            break;
    }
    if (total == 0) std :: cout << "Correct!\n";
    else std ::cout << "Wrong!\n";
    fin.close();

    fin.open("test.in");//-----------------------------use stack to solve
    stack<char> s;
    int flag = 1;
    for (; fin >> c ;){
        if (c == '(') s.push(c);
        else if (c == ')'){
            if (!s.empty()) s.pop();
            else {
                flag = 0;
                break;
            }
        }
    }
    if (flag) std :: cout << "Correct!\n";
    else std :: cout << "Wrong!\n";
    return 0;
}
