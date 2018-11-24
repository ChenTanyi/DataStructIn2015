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

#endif // function_H
