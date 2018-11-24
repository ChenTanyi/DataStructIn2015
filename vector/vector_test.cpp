#include "vector.h"
#include <iostream>

int main(){
    vector <int> v1(4,3);
    for (int i = 0 ; i < 10 ; ++i)
        v1.push_back(i);
    vector <int> :: iterator it = v1.begin() + 10;
    v1.erase(it,v1.end());
    v1.pop_back();
    for (int i = 0 ; i < v1.size() ; ++i){
        std :: cout << v1[i] << " ";
    }
    std :: cout << std :: endl;
    for (vector<int> :: reverse_iterator rit = v1.rbegin() ; rit != v1.rend() ; ++ rit){
        std :: cout << *rit << " ";
    }
    std :: cout << std :: endl;
    std :: cout << v1.empty() << std :: endl;
    std :: cout << v1.size() << std :: endl;
    std :: cout << v1.capacity() << std :: endl;

    vector <int> v2 = v1;
    std ::cout << (v2.begin() == v1.begin() ? "v1 == v2" : "v1 != v2") << std :: endl;
    for (vector<int> :: reverse_iterator rit = v2.rbegin() ; rit != v2.rend() ; ++ rit){
        std :: cout << *rit << " ";
    }
    std :: cout << std :: endl;

    vector <int> v3;
    v3 = v1;
    std ::cout << (v3.begin() == v1.begin() ? "v1 == v3" : "v1 != v3") << std :: endl;
    for (vector<int> :: const_reverse_iterator rit = v3.rbegin() ; rit != v3.rend() ; ++ rit){
        std :: cout << *rit << " ";
    }
    std :: cout << std :: endl;

    v1.clear();
    std :: cout << v1.empty() << std :: endl;
    v1.resize(17);
    std :: cout << v1.size() << std :: endl;
    std :: cout << v1.capacity() << std :: endl;


    vector < std :: pair < int , int > > vp;
    vp.push_back(std :: make_pair(1,2));
    for (vector <std :: pair < int , int > > :: reverse_iterator rit = vp.rbegin() ; rit != vp.rend() ; ++ rit){
        std :: cout << rit -> first << " " << rit -> second << std :: endl;
    }


    vector<int>  v;

    std :: cout << "the initial size of v is: "<< v.size()
            <<"\n the initial capacity of v is: "
            << v.capacity() << std :: endl;
    v.push_back(2);
    std :: cout << "\n after push 2, capacity of v is: "
        << v.capacity() << std :: endl;
    v.push_back(3);
    std :: cout << "\n after pust 3, capacity of v is: "
        << v.capacity() << std :: endl;
    v.push_back(4);
    std :: cout << "\n after push 4, capacity of v is: "
         << v.capacity() << std :: endl;

    std :: cout<<"\n the size of v is:  "<< v.size()
       << "\n the capacity of v is : "
       << v.capacity() << std :: endl;

    std :: cout<<"\n contents of  v using [ ]: ";

    for (int i=0; i<v.size(); i++)
          std :: cout << v[i] << "   ";
    std :: cout << std :: endl;

    std :: cout<<"\n contents of  v using iterator notation: ";
    vector<int>::const_iterator p;
    for (p=v.begin(); p!=v.end(); p++)
          std :: cout << *p << "   ";
    std :: cout << std :: endl;

    return 0;
}
