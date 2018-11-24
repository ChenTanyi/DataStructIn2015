#ifndef Exercise1_H
#define Exercise1_H

#include "BST.h"
#include "function.h"
#include "pair.h"
#include <string>

class City{
/*private:
	struct cmp{
		bool operator()(char* a, char* b){
			int i = 0;
			for (; a[i] && b[i] ; ++ i){
				if (a[i] != b[i])
					return a[i] < b[i];
			}
			if (a[i]) return 1;
			return 0;
		}
	};*/
protected:
	typedef pair<std :: string, pair<int, int> > value_type;
	typedef BST<std :: string, value_type, Select1st<value_type>, less<std :: string> > Tree;


	Tree tree;


public:
	typedef typename Tree::iterator iterator;
	typedef typename Tree::const_iterator const_iterator;

	City():tree(){}

	iterator begin(){return tree.begin();}
	const_iterator begin() const {return tree.begin();}
	iterator end() {return tree.end();}
	const_iterator end() const {return tree.end();}

	void insert(const value_type& v){tree.insert(v);}


	void erase(const std :: string& s){tree.erase(s);}
	void erase(const pair<int, int>&);


	iterator find(const std :: string& s){return tree.find(s);}
	iterator find(const pair<int, int>&);
};

#endif // Exercise1_H
