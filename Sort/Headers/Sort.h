#ifndef Sort_H
#define Sort_H

#include "queue.h"
#include "function.h"

template <typename Value>
class Sort{
public:
	template <typename Iterator>
	static Value firstSort(Iterator first, Iterator last, int k);

	template <typename Iterator>
	static Value secondSort(Iterator first, Iterator last, int k);
};


template <typename Value>
template <typename Iterator>
Value Sort<Value>::firstSort(Iterator first, Iterator last, int k){
	priority_queue<Value> q(first, last);//建一个n个元素的大根堆
	for (int i = 1 ; i < k ; ++ i) q.pop();//弹出的第k个元素就是所求
	return q.top();                         //时间复杂度O(N + k log N)
}

template <typename Value>
template <typename Iterator>
Value Sort<Value>::secondSort(Iterator first, Iterator last, int k){
	priority_queue<Value, vector<Value>, greater<Value> > q;
	Iterator it = first;
	for (int i = 0; i < k ; ++ it, ++ i) q.push(*it);//建一个k个元素的小根堆
	for ( ; it != last ; ++ it){//余下的，如果值比堆顶的元素大，则弹出堆顶，插入该元素
		if (*it > q.top()){                             //时间复杂度O(N log k)
			q.pop();
			q.push(*it);
		}
	}
	return q.top();
}


#endif // Sort_H
