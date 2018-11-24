#include "CircularLinkList.h"

int main(){
    int n , m ;
    std :: cin >> n >> m;--m;
    CircularLinkList <int> l;
    for (int i = 0 ; i < n ; ++ i){
        l.append(i+1);
    }
    int num ;
    while (l.length() > 1){
        l.move(m);
        l.remove(num);
        //std :: cout << "The " << num << "th people is killed.\n";
    }
    l.moveToStart();l.getValue(num);
    std :: cout << num << std :: endl;
    //std :: cout << "The " << num << "th people is survived.\n";
    return 0;
}
