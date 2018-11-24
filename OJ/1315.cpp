#include <iostream>
#include <queue>

struct frac{
    int num, den;
    frac(const int _num = 0 , const int _den = 1):num(_num), den(_den){}
};

bool operator < (const frac & a , const frac & b){
    return a.num * b.den > b.num * a.den;
}

std :: ostream & operator << (std::ostream & os , const frac & a){
    os << a.num << "/" << a.den;
    return os;
}

template <typename T>
T gcd(T a, T b){
    for (; b ; a %= b , std :: swap(a,b));
    return a;
}

std :: priority_queue<frac> q;

int main(){
    int n;
    std :: cin >> n;
    std :: cout << "0/1";
    for (int i = 2 ; i <= n ; ++ i){
        for (int j = 1 ; j < i ; ++ j){
            if (gcd(i,j) == 1){
                q.push(frac(j,i));
            }
        }
    }
    while (!q.empty()){
        std :: cout << " " << q.top();
        q.pop();
    }
    std :: cout << " 1/1\n";
    return 0;
}
