#ifndef function_H
#define function_H

//define the compare functional class

template <typename T>
struct equal_to{
    bool operator() (const T & a, const T & b){
        return a == b;
    }
};

template <typename T>
struct less{
    bool operator() (const T & a, const T & b){
        return a < b;
    }
};

template <typename T>
struct greater{
    bool operator() (const T & a, const T & b){
        return a > b;
    }
};

template <typename T>
struct not_equal_to{
    bool operator() (const T & a, const T & b){
        return a != b;
    }
};

template <typename T>
struct greater_equal{
    bool operator() (const T & a, const T & b){
        return a >= b;
    }
};

template <typename T>
struct less_equal{
    bool operator() (const T & a, const T & b){
        return a <= b;
    }
};

template <typename T>
struct Identity{
	T& operator() (T& a){
		return a;
	}
	const T& operator() (const T& a){
		return a;
	}
};

template <typename Pair>
struct Select1st{
	typename Pair::first_type& operator() (Pair & a){
		return a.first;
	}
	const typename Pair::first_type& operator() (const Pair & a){
		return a.first;
	}
};

template <typename Pair>
struct Select2nd{
	typename Pair::second_type& operator() (Pair & a){
		return a.second;
	}
	const typename Pair::second_type& operator() (const Pair & a){
		return a.second;
	}
};

#endif // function_H
