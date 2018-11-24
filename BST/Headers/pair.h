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
	inline friend bool operator==(const pair& a, const pair& b){
		return a.first == b.first && a.second == b.second;
	}
	inline friend bool operator!=(const pair& a, const pair& b){
		return !(a == b);
	}
	inline friend bool operator<(const pair& a, const pair& b){
		return a.first < b.first || (!(b.first < a.first) && a.second < b.second);
	}
	inline friend bool operator<=(const pair& a, const pair& b){
		return !(b < a);
	}
	inline friend bool operator>(const pair& a, const pair& b){
		return b < a;
	}
	inline friend bool operator>=(const pair& a, const pair& b){
		return !(a < b);
	}
};

template <typename T1, typename T2>
pair<T1,T2> make_pair(const T1 & a, const T2 & b){
    return pair<T1,T2>(a,b);
}

template <typename T1, typename T2>
pair<T1,T2> makePair(const T1 & a, const T2 & b){
    return pair<T1,T2>(a,b);
}


#endif // pair_H
