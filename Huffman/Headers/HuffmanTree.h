#ifndef Huffman_H
#define Huffman_H

//使用优先队列构造哈夫曼树

#include "queue.h"
#include "pair.h"

typedef vector<char> HuffSource;
typedef vector<bool> HuffCode;
typedef vector< pair<char,HuffCode> > HuffCodeMap;

template <typename Value> class HuffTree;

template <typename Value>  //哈夫曼树的节点，作为叶节点和内节点的基类
class HuffNode{
protected:
	int w;
public:
	HuffNode(const int & wei = 0)
		:w(wei){}
    virtual ~HuffNode(){}
    int & weight() {return w;}
	const int & weight() const {return w;}
	virtual bool leaf() const = 0;
	virtual HuffNode* left() {HuffNode<Value>* h = NULL;return h;}//定义这四个虚函数只是为了调用子类函数
	virtual HuffNode* right() {HuffNode<Value>* h = NULL;return h;}
	virtual const Value & value() const {return Value();}
	virtual Value & value() {Value v = Value();return v;}
};

struct MaxTreeComp{//定义函数类来构造优先队列
	template<typename Value>
	bool operator() (HuffTree<Value>* a, HuffTree<Value>* b){
		return a -> weight() > b -> weight();
	}
};

template <typename Value>
class InternalNode : public HuffNode<Value>{//内节点类
protected:
	HuffNode<Value>* leftNode;
	HuffNode<Value>* rightNode;
public:
	InternalNode(HuffNode<Value>* l, HuffNode<Value>* r)
		:HuffNode<Value>(l -> weight() + r -> weight()), leftNode(l), rightNode(r) {}
	HuffNode<Value>* left() {return leftNode;}
	HuffNode<Value>* right() {return rightNode;}
	bool leaf() const {return 0;}
};

template <typename Value>
class LeafNode : public HuffNode<Value>{//叶节点类
protected:
	Value v;
public:
	LeafNode(const Value & val = Value(), const int & w = 0)
		:HuffNode<Value>(w), v(val) {}
	Value & value() {return v;}
    const Value & value() const {return v;}
	bool leaf() const {return 1;}
};

template <typename Value>
class HuffTree{
private:
	void destroy(HuffNode<Value>*);

protected:
	HuffNode<Value>* rootNode;

public:
	HuffTree(const Value & v,int w){//构造叶节点
		rootNode = new LeafNode<Value>(v,w);
	}

	HuffTree(HuffTree* l, HuffTree* r){//构造内节点
		rootNode = new InternalNode<Value>(l -> root(), r -> root());
	}

	template <typename Iterator>//建树
	static HuffTree* build(Iterator first, Iterator last);

	template <typename Sequence>
	static HuffTree* build(Sequence c){return build(c.begin(), c.end());}

	~HuffTree(){destroy(rootNode);}
	HuffNode<Value>* root() {return rootNode;}
	void setRoot(HuffNode<Value>* p){rootNode = p;}
	int & weight() {return root()->weight();}
	const int & weight() const {return root()->weight();}

};

template <typename Value>
void HuffTree<Value>::destroy(HuffNode<Value>* parent){
	if (!parent->leaf()){
		destroy(parent->left());
		destroy(parent->right());
		delete parent;
	}
}

template <typename Value>
template <typename Iterator>
HuffTree<Value>* HuffTree<Value>::build(Iterator first, Iterator last){
	priority_queue<HuffTree<Value>*, vector<HuffTree<Value>*>, MaxTreeComp> q(first, last);
	HuffTree<Value> *tmp1, *tmp2, *tmp3;
	while (q.size() > 1){
		tmp1 = q.top(); q.pop();
		tmp2 = q.top(); q.pop();
		tmp3 = new HuffTree<Value>(tmp1, tmp2);
		q.push(tmp3);
	}
	return tmp3;
}

#endif // Huffman_H
