#ifndef queue_H
#define queue_H

/*
 *  use the heap to build a priority queue
 */

#include <cassert>
#include "vector.h"
#include "function.h"
#include "heap.h"

template <typename Value, typename Sequence = vector<Value>, typename Compare = less<typename Sequence::value_type> >
class priority_queue{
public:
    typedef  typename   Sequence::value_type       	value_type;
    typedef  typename   Sequence::reference        	reference;
    typedef  typename   Sequence::const_reference  	const_reference;
    typedef             Sequence                   	container_type;
protected:
	Sequence c;
	Compare comp;
public:
	explicit priority_queue(const Sequence & s = Sequence(), const Compare & x = Compare());
	template <typename Iterator>
	explicit priority_queue(Iterator first, Iterator last, const Sequence & s = Sequence(), const Compare & x = Compare());

	bool empty() const {return c.empty();}
	int size() const {return c.size();}
	const_reference top() const {assert(!empty()); return c.front();}

	void push(const value_type & x);
	void pop();
};


//---------------------------definition-----------------------------------------------------


template <typename Value, typename Sequence, typename Compare>
priority_queue<Value,Sequence,Compare>::priority_queue(const Sequence & s, const Compare & x)
	: c(s), comp(x)
	{make_heap(c.begin(), c.end(), comp);}

template <typename Value, typename Sequence, typename Compare>
template <typename Iterator>
priority_queue<Value,Sequence,Compare>::priority_queue(Iterator first, Iterator last, const Sequence & s, const Compare & x)
	: c(s), comp(x){
	c.insert(c.end(), first, last);
	make_heap(c.begin(), c.end(), comp);
}

template <typename Value, typename Sequence, typename Compare>
void priority_queue<Value,Sequence,Compare>::push(const value_type & x){
	c.push_back(x);
	push_heap(c.begin(), c.end(), comp);
}

template <typename Value, typename Sequence, typename Compare>
void priority_queue<Value,Sequence,Compare>::pop(){
	if (!empty()){
		pop_heap(c.begin(), c.end(), comp);
		c.pop_back();
	}
}

#endif // queue_H
