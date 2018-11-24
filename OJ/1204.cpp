#include <iostream>
#include <cstdio>

char s[111][2222];
char buffer[111];
int length[111] , t = 0;

void list(){
    int l , r ;
    std :: cin >> l >> r;
    --l , -- r;
    if (0 <= l && l < t && 0 <= r && r < t && l <= r){
        for (int i = l ; i <= r ; ++ i){
            puts(s[i]);
        }
    }
    else puts("Error!");
}

void ins(){
    int x , y;
    std :: cin >> x >> y;
    --x , -- y;
    char c;
    scanf("%c",&c);
    gets(buffer);
    if (0 <= x && x < t && 0 <= y && y <= length[x]){
        int l = 0;
        for (; buffer[l] ; ++ l);
        int tail = length[x] + l;
        s[x][tail] = 0;
        for (int i = tail - 1 ; i >= l + y ; -- i){
            s[x][i] = s[x][i - l];
        }
        for (int i = y , j = 0; j < l ; ++ j , ++ i){
            s[x][i] = buffer[j];
        }
        length[x] = tail;
    }
    else puts("Error!");
}

void del(){
    int x, y , num;
    std :: cin >> x >> y >> num;
    --x , -- y;
    if (0 <= x && x < t && 0 <= y && y < length[x] && 0 <= num && y + num <= length[x]){
        for (int i = y , j = y + num ; j <= length[x] ; ++ j , ++ i){
            s[x][i] = s[x][j];
        }
        length[x] -= num;
    }
    else puts("Error!");
}

int main(){
//freopen("debug.in","r",stdin);
    while (1){
        gets(s[t]);
        int flag = 1;
        int i;
        for (i = 0 ; s[t][i] ; ++ i);
        length[t] = i;
        for (int i = 0 ; i < 6 ; ++ i){
            if (s[t][i] != '*') flag = 0;
        }
        if (s[t++][6]) flag = 0;
        if (flag) {--t;break;}
    }
    while (1){
        std :: cin >> buffer;
        if (buffer[0] == 'q'){
            for (int i = 0 ; i < t ; ++ i){
                puts(s[i]);
            }
            break;
        }
        else if (buffer[0] == 'l') list();
        else if (buffer[0] == 'i') ins();
        else del();
    }
    return 0;
}
