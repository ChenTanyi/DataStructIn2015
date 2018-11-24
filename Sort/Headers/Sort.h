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
	priority_queue<Value> q(first, last);//��һ��n��Ԫ�صĴ����
	for (int i = 1 ; i < k ; ++ i) q.pop();//�����ĵ�k��Ԫ�ؾ�������
	return q.top();                         //ʱ�临�Ӷ�O(N + k log N)
}

template <typename Value>
template <typename Iterator>
Value Sort<Value>::secondSort(Iterator first, Iterator last, int k){
	priority_queue<Value, vector<Value>, greater<Value> > q;
	Iterator it = first;
	for (int i = 0; i < k ; ++ it, ++ i) q.push(*it);//��һ��k��Ԫ�ص�С����
	for ( ; it != last ; ++ it){//���µģ����ֵ�ȶѶ���Ԫ�ش��򵯳��Ѷ��������Ԫ��
		if (*it > q.top()){                             //ʱ�临�Ӷ�O(N log k)
			q.pop();
			q.push(*it);
		}
	}
	return q.top();
}


#endif // Sort_H
