#ifndef pair_H
#define pair_H

/*
 *  create a struct holding two objects of arbitrary type
 */

template <typename T1, typename T2>
struct pair{
    typedef     T1      first_type;
    typedef     T2      second_type;
    T1 first;
    T2 second;
    pair(const T1 & a = T1(), const T2 & b = T2())
        :first(a), second(b){}
    pair(const pair & p):first(p.first), second(p.second){}
};

template <typename T1, typename T2>
pair<T1,T2> make_pair(const T1 & a, const T2 & b){
    return pair<T1,T2>(a,b);
}

#endif // pair_H
