#ifndef BSTIterator_H
#define BSTIterator_H

/*
 *    二叉搜索树迭代器的定义
 */

#include "BSTNode.h"

template <typename Value>
class BSTIterator{
public:
	typedef Value value_type;
	typedef Value& reference;
	typedef Value* pointer;
	typedef BSTIterator<Value> self;
	typedef BSTNode<Value>* link_type;

    link_type base() {return node;}
	void increment();//获取后驱节点
	void decrement();//获取前驱节点

	BSTIterator(){}
	explicit BSTIterator(link_type x) {node = x;}

	reference operator*() {return node->value();}
	pointer operator->() {return &(operator*());}

	self& operator++(){increment();return *this;}
	self operator++(int){
		self tmp = *this;
		increment();
		return tmp;
	}

	self& operator--(){decrement();return *this;}
	self operator--(int){
		self tmp = *this;
		decrement();
		return tmp;
	}

	inline friend bool operator==(const self & a, const self & b){return a.node == b.node;}
	inline friend bool operator!=(const self & a, const self & b){return a.node != b.node;}
	
	
protected:
    link_type node;
};


template <typename Value>
class BSTConstIterator{
public:
	typedef Value value_type;
	typedef const Value& reference;
	typedef const Value* pointer;
	typedef BSTIterator<Value> iterator;
	typedef BSTConstIterator<Value> self;
	typedef BSTNode<Value>* link_type;

    link_type base() {return node;}
	void increment();
	void decrement();

	BSTConstIterator(){}
	explicit BSTConstIterator(link_type x) {node = x;}
	BSTConstIterator(const iterator& x) {node = x.base();}

	reference operator*() {return node->value();}
	pointer operator->() {return &(operator*());}

	self& operator++(){increment();return *this;}
	self operator++(int){
		self tmp = *this;
		increment();
		return tmp;
	}

	self& operator--(){decrement();return *this;}
	self operator--(int){
		self tmp = *this;
		decrement();
		return tmp;
	}

	inline friend bool operator==(const self & a, const self & b){return a.node == b.node;}
	inline friend bool operator!=(const self & a, const self & b){return a.node != b.node;}
	
	
protected:
    link_type node;
};

template <typename Value>
void BSTIterator<Value>::increment(){
	if (node->right()){
		node = node->right();
		while (node->left())
			node = node->left();
	}
	else {
		link_type y = node->parent();
		while (node == y->right()){
			node = y;
			y = y->parent();
		}
		if (node->right() != y){
			node = y;
		}
	}
}

template <typename Value>
void BSTIterator<Value>::decrement(){
    if (node->parent()->parent() == node)
        node = node->right();
	else if (node->left()){
		node = node->left();
		while (node->right())
			node = node->right();
	}
	else {
		link_type y = node->parent();
		while (node == y->left()){
			node = y;
			y = y->parent();
		}
        node = y;
	}
}

template <typename Value>
void BSTConstIterator<Value>::increment(){
	if (node->right()){
		node = node->right();
		while (node->left())
			node = node->left();
	}
	else {
		link_type y = node->parent();
		while (node == y->right()){
			node = y;
			y = y->parent();
		}
		if (node->right() != y){
			node = y;
		}
	}
}

template <typename Value>
void BSTConstIterator<Value>::decrement(){
    if (node->parent()->parent() == node)
        node = node->right();
	else if (node->left()){
		node = node->left();
		while (node->right())
			node = node->right();
	}
	else {
		link_type y = node->parent();
		while (node == y->left()){
			node = y;
			y = y->parent();
		}
        node = y;
	}
}

#endif // BSTiterator_H
