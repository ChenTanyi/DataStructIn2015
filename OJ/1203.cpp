#include <iostream>
#include <cstdio>

const int N =1e5+10;

void addInt(int * a , int n , int * b , int m , int * c){
    for (int i = 0 ; i < n ; ++ i){
        c[i] = a[i];
    }
    for (int i = 0 ; i < m ; ++ i){
        c[i + n] = b[i];
    }
}

void addDouble(double * a , int n , double * b , int m , double * c){
    for (int i = 0 ; i < n ; ++ i){
        c[i] = a[i];
    }
    for (int i = 0 ; i < m ; ++ i){
        c[i + n] = b[i];
    }
}

void addChar(char * a , int n , char * b , int m , char * c){
    for (int i = 0 ; i < n ; ++ i){
        c[i] = a[i];
    }
    for (int i = 0 ; i < m ; ++ i){
        c[i + n] = b[i];
    }
}

int a[N], b[N] , c[2*N];
double aa[N], bb[N], cc[2*N];
char aaa[N], bbb[N], ccc[2*N];

int main(){
    char s[11];
    gets(s);
    int n , m;
    scanf("%d%d",&n,&m);
    if (s[0] == 'i'){
        for (int i = 0; i < n ; ++ i){
            std :: cin >> a[i];
        }
        for (int i = 0; i < m ; ++ i){
            std :: cin >> b[i];
        }
        addInt(a,n,b,m,c);
        for (int i = 0 ; i < n + m - 1 ; ++ i){
            std :: cout << c[i] << " ";
        }
        std :: cout << c[n+m-1] << "\n";
    }
    else if (s[0] == 'd'){
        for (int i = 0; i < n ; ++ i){
            std :: cin >> aa[i];
        }
        for (int i = 0; i < m ; ++ i){
            std :: cin >> bb[i];
        }
        addDouble(aa,n,bb,m,cc);
        for (int i = 0 ; i < n + m - 1 ; ++ i){
            std :: cout << cc[i] << " ";
        }
        std :: cout << cc[n+m-1] << "\n";
    }
    else {
        for (int i = 0; i < n ; ++ i){
            std :: cin >> aaa[i];
        }
        for (int i = 0; i < m ; ++ i){
            std :: cin >> bbb[i];
        }
        addChar(aaa,n,bbb,m,ccc);
        for (int i = 0 ; i < n + m - 1 ; ++ i){
            std :: cout << ccc[i] << " ";
        }
        std :: cout << ccc[n+m-1] << "\n";
    }
    return 0;
}
