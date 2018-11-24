#ifndef BST_H
#define BST_H

/*
 *  二叉搜索树类的定义
 */

#include <iostream>
#include "BSTNode.h"
#include "BSTIterator.h"
#include "iterator.h"
#include "pair.h"

template <typename Key, typename Value, typename KeyOfValue, typename Compare>//Key为关键字，Value为变量值
class BST{											//KeyOfValue为值转化关键字函数类,Compare为关键字比较函数类
protected:
	typedef BSTNode<Value> node;

public:
	typedef Key key_type;
	typedef Value value_type;
	typedef Value& reference;
	typedef const Value& const_reference;
	typedef Value* pointer;
	typedef const Value* const_pointer;
	typedef typename node::link_type link_type;
	typedef size_t size_type;

protected:
	size_type nodeCount;//记录节点个数
	link_type header;//记录根节点，最大值，最小值
	Compare keyCompare;//关键字比较函数类

public:
	BST(const Compare& comp = Compare()):nodeCount(0), keyCompare(comp), header(0){init();}
	~BST(){clear();delete header;}

	link_type& root() const {return header->parent();}//根节点
	link_type& min() const {return header->left();}//最小值
	link_type& max() const {return header->right();}//最大值

	static link_type& parent(link_type x) {return x->parent();}
	static link_type& left(link_type x) {return x->left();}
	static link_type& right(link_type x) {return x->right();}
	static reference value(link_type x) {return x->value();}
	static const Key& key(link_type x) {return KeyOfValue()(value(x));}


	typedef BSTIterator<Value> iterator;
	typedef BSTConstIterator<Value> const_iterator;
	typedef reverseIterator<iterator> reverse_iterator;
	typedef reverseIterator<const_iterator> const_reverse_iterator;


	static link_type minimum(link_type x);
	static link_type maximum(link_type x);


	bool empty() const {return nodeCount == 0;}
	size_type size() const {return nodeCount;}

	iterator begin() {return iterator(min());}
	const_iterator begin() const {return const_iterator(min());}
	iterator end() {return iterator(header);}
	const_iterator end() const {return const_iterator(header);}

	reverse_iterator rbegin() {return reverse_iterator(end());}
	const_reverse_iterator rbegin() const {return const_reverse_iterator(end());}
	reverse_iterator rend() {return reverse_iterator(begin());}
	const_reverse_iterator rend() const {return const_reverse_iterator(begin());}

	void clear();
	iterator erase(iterator position);//删除position处的节点
	size_type erase(const key_type& x);//删除关键字为x的所有节点
	iterator erase(iterator first, iterator last);//删除从first到last(不包括)的所有节点
	void erase(const key_type* first, const key_type* last);//删除关键字为first到last(不包括)中任一个的节点

	iterator insert(const_reference);//插入一个节点
	template <typename Iterator>
	void insert(Iterator first, Iterator last);//插入first到last(不包括)的所有值

	iterator find(const key_type&);//通过关键字寻找某个节点
	iterator lower_bound(const key_type&);//寻找下限
	iterator upper_bound(const key_type&);//寻找上限
	pair<iterator, iterator> equal_range(const key_type&);//寻找等于某个关键字的所有节点

private:
	void init();
	//void destroy(link_type x);
	//iterator privateInsert(link_type x, link_type y, const_reference v);
	void privateErase(link_type x);
};


//------------------------------definition---------------------------------------------

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void BST<Key, Value, KeyOfValue, Compare>::init(){
	if (!header) header = new node;
	root() = 0;
	min() = header;
	max() = header;
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::link_type
BST<Key, Value, KeyOfValue, Compare>::minimum(link_type x){
	while (x->left()) x = x->left();
	return x;
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::link_type
BST<Key, Value, KeyOfValue, Compare>::maximum(link_type x){
	while (x->right()) x = x->right();
	return x;
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void BST<Key, Value, KeyOfValue, Compare>::clear(){
	if (size()){
		privateErase(root());
		root() = 0;
		min() = header;
		max() = header;
		nodeCount = 0;
	}
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void BST<Key, Value, KeyOfValue, Compare>::privateErase(link_type x){
	while (x){
		privateErase(right(x));
		link_type y = left(x);
		delete x;
		x = y;
	}
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::iterator
BST<Key, Value, KeyOfValue, Compare>::erase(iterator position){
	if (empty() || position == end()) return end();
	--nodeCount;
	link_type z = (position++).base();
	link_type y = z;
	link_type x = 0;
	if (y->left() == 0)             // z has at most one non-null child. y == z.
		x = y->right();               // x might be null.
	else
		if (y->right() == 0)          // z has exactly one non-null child.  y == z.
			x = y->left();              // x is not null.
		else {                      // z has two non-null children.  Set y to
			y = y->right();             //   z's successor.  x might be null.
			while (y->left() != 0)
				y = y->left();
			x = y->right();
    }
	if (y != z) {                 // relink y in place of z.  y is z's successor
		z->left()->parent() = y;
		y->left() = z->left();
		if (y != z->right()) {
			if (x) x->parent() = y->parent();
			y->parent()->left() = x;      // y must be a left child
			y->right() = z->right();
			z->right()->parent() = y;
		}
		if (root() == z)
			root() = y;
		else if (z->parent()->left() == z)
			z->parent()->left() = y;
		else
			z->parent()->right() = y;
		y->parent() = z->parent();
		y = z;
    // y now points to node to be actually deleted
	}
	else {                        // y == z
		if (x) x->parent() = y->parent();
		if (root() == z)
			root() = x;
		else
		if (z->parent()->left() == z)
			z->parent()->left() = x;
		else
			z->parent()->right() = x;
		if (min() == z)
			if (z->right() == 0)        // z->left must be null also
				min() = z->parent();
    // makes leftmost == header if z == root
			else
				min() = minimum(x);
		if (max() == z)
			if (z->left() == 0)         // z->right must be null also
				max() = z->parent();
    // makes rightmost == header if z == root
			else                      // x == z->left
				max() = maximum(x);
	}
	delete y;
	return position;
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::size_type
BST<Key, Value, KeyOfValue, Compare>::erase(const key_type& x){
	pair<iterator, iterator> p = equal_range(x);
	size_type oldSize = size();
	erase(p.first, p.second);
	return oldSize - size();
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::iterator
BST<Key, Value, KeyOfValue, Compare>::erase(iterator first, iterator last){
	if (first == begin() && last == end())
		clear();
	else while (first != last)
		erase(first++);
	return last;
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
void BST<Key, Value, KeyOfValue, Compare>::erase(const key_type* first, const key_type* last){
	while (first != last) erase(*first++);
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::iterator
BST<Key, Value, KeyOfValue, Compare>::insert(const_reference v){
	link_type y = header;
	link_type x = root();
	while (x){
		y = x;
		x = keyCompare(KeyOfValue()(v), key(x))? left(x) : right(x);
	}
	x = new node(v, y);
	if (y == header){
        root() = x;
		min() = x;
		max() = x;
	}
	else if (keyCompare(key(x), key(y))){
		left(y) = x;
		if (y == min())
			min() = x;
	}
	else{
		right(y) = x;
		if (y == max())
			max() = x;
	}
	++nodeCount;
	return iterator(x);
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
template <typename Iterator>
void BST<Key, Value, KeyOfValue, Compare>::insert(Iterator first, Iterator last){
	while (first != last)
		insert(*first++);
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::iterator
BST<Key, Value, KeyOfValue, Compare>::find(const key_type& k){
	iterator j = lower_bound(k);
	return (j == end() || keyCompare(k, key(j.base())))? end() : j;
}


template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::iterator
BST<Key, Value, KeyOfValue, Compare>::lower_bound(const key_type& k){
	link_type y = header;
	link_type x = root();
	while (x){
		if (!keyCompare(key(x), k))
			y = x , x = left(x);
		else x = right(x);
	}
	return iterator(y);
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
typename BST<Key, Value, KeyOfValue, Compare>::iterator
BST<Key, Value, KeyOfValue, Compare>::upper_bound(const key_type& k){
	link_type y = header;
	link_type x = root();
	while (x){
		if (keyCompare(k, key(x)))
			y = x , x = left(x);
		else x = right(x);
	}
	return iterator(y);
}

template <typename Key, typename Value, typename KeyOfValue, typename Compare>
pair<typename BST<Key, Value, KeyOfValue, Compare>::iterator,
     typename BST<Key, Value, KeyOfValue, Compare>::iterator>
BST<Key, Value, KeyOfValue, Compare>::equal_range(const key_type& k){
	return pair<iterator, iterator>(lower_bound(k), upper_bound(k));
}

#endif // BST_H
