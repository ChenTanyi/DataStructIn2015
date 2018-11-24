#include "../Headers/Exercise1.h"

void City::erase(const pair<int, int>& p){
    for (iterator it = begin(); it != end();){
        if (it->second == p)
            tree.erase(it++);
        else ++it;
    }
}

typename City::iterator City::find(const pair<int, int>& p){
    for (iterator it = begin(); it != end(); ++ it){
        if (it->second == p)
            return it;
    }
    return end();
}
