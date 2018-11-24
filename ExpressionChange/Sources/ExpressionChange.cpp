#include <iostream>
#include <cstdio>
#include "stack.h"

char prior [10][10]={                                   //judge for the priority of the operator
    // +-*/()#^M
 /*+*/">><<<>><<",
 /*-*/">><<<>><<",
 /***/">>>><>><<",
 /*/*/">>>><>><<",
 /*(*/"<<<<<= <<",
 /*)*/">>>> >>>>",
 /*#*/"<<<<< =<<",
 /*^*/">>>><>><<",
 /*M*/">>>><>>>>"
};

int opNum[129];                                         //get the operator number

void init(){
    opNum['+'] = 0;
    opNum['-'] = 1;
    opNum['*'] = 2;
    opNum['/'] = 3;
    opNum['('] = 4;
    opNum[')'] = 5;
    opNum['#'] = 6;
    opNum['^'] = 7;
    opNum['M'] = 8;
}

char percede(char op1 , char op2){                      //get the priority between two operators
    return prior[opNum[op1]][opNum[op2]];
}

stack<char> sc;                                         //stack<char> to store operator
char s[111];                                            //char [] to get the expression

void work(){
    gets(s);
    char * buffer = s;
    for( ; * buffer ; ++ buffer);
    *buffer = '#' , *(buffer +1 ) = 0;
    sc.push('#');                                       //'#' for check the two side of the expression
    int flag = 1;
    for ( buffer = s ; * buffer || !sc.empty();){
        char c = *buffer;
        if (c == ' ') {
            ++buffer;
            continue;
        }
        if ('0' <= c && c <= '9'){                      //if the input is number, read the number and print it
            int x ;
            sscanf(buffer,"%d",&x);
            while ('0' <= *buffer && *buffer <= '9') ++ buffer;
            if (flag) {
                printf("%d",x);
                flag = 0;
            }
            else printf(" %d",x);
        }
        else{                                           //else the input is operator
            char op = sc.top();                         //compared with the top value of stack
            switch(percede(op,c)){
            case '<':                                   //the priority of the input is high, push it into the stack
                sc.push(c);
                ++ buffer;
                break;
            case '=':                                   //the brackets are in pairs
                sc.pop();
                ++ buffer;
                break;
            case '>':                                   //the priority of the input is low, print the top value of the stack
                printf(" %c",op);
                sc.pop();
            }
        }
    }
    puts("");
}
