#ifndef stack_H
#define stack_H
#include "vector.h"

template <typename _Tp , typename _Sequence = vector<_Tp> >//using the vector in the second homework as container
class stack{//-----------------------------------------------to build the stack.
public:
    typedef  typename   _Sequence::value_type       value_type;
    typedef  typename   _Sequence::reference        reference;
    typedef  typename   _Sequence::const_reference  const_reference;
    typedef             _Sequence                   container_type;
protected:
    _Sequence c;
public:
    explicit stack(const _Sequence _c = _Sequence()): c(_c) {} // constructor
    bool empty() const {return c.empty();} //check empty or not
    void clear() {c.clear();} //clear the stack
    int size() const {return c.size();} //return the stack size
    reference top() {return c.back();} //return the stack top value
    const_reference top() const {return c.back();} //return the stack top value as const reference
    void push(const value_type & _value) {c.push_back(_value);} //push an element into the stack
    void pop() {c.pop_back();} //pop the top element of the stack
};

#endif // stack_H
