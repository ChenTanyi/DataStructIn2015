#ifndef BSTNode_H
#define BSTNode_H

template <typename Value>
class BSTNode{
public:
	typedef BSTNode<Value>* link_type;
private:
	Value _value;
	link_type _parent;
	link_type _left;
	link_type _right;
public:
	BSTNode(const Value & value = Value(), BSTNode* parent = 0, BSTNode* left = 0, BSTNode* right = 0):
		_value(value), _parent(parent), _left(left), _right(right){}
	Value& value() {return _value;}
	link_type& parent() {return _parent;}
	link_type& left() {return _left;}
	link_type& right() {return _right;}
};

#endif // BSTNode_H
