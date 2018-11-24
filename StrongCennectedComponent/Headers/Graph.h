#ifndef Graph_H
#define Graph_H

#include "vector.h"
#include "stack.h"
#include <map>

template <typename Ver, typename Edge>
class Graph{
private:
	struct node{
		int v;
		Edge w;
		node* next;
		node(int ver, const Edge& weight = Edge(), node* nxt = 0):v(ver), w(weight), next(nxt){}
	};
public:
	Graph(int, const Ver*, bool = 1, const Edge& = -1);
	~Graph(){}
	bool eraseEdge(const Ver&, const Ver&);
	bool addEdge(const Ver&, const Ver&, const Edge&);
	bool exist(const Ver&, const Ver&) const;
	Edge find(const Ver&, const Ver&) const;

	template <typename ResultContainer>
	bool Tarjan(ResultContainer&) const;//用Tarjan算法求强连通分量，结果保留在参数中，返回是否成功，参数两维，每个一维代表一个强连通分量

private:
	const int size;
	const Edge noEdge;
	const bool isDirected;
	vector<Ver> vertics;
	vector< node* > edges;
	std::map<Ver, int> verToPos;

	template <typename PosContainer, typename FlagContainer, typename StackContainer, typename ResultContainer>
	void Tarjandfs(int, int&, PosContainer&, PosContainer&, FlagContainer&, StackContainer&, ResultContainer&) const;

};


template <typename Ver, typename Edge>
Graph<Ver, Edge>::Graph(int verSize, const Ver* v, bool directed, const Edge& none)
	:size(verSize), noEdge(none), isDirected(directed), vertics(v, v + verSize), edges(verSize, 0){
	for (int i = 0 ; i < size ; ++ i){
		verToPos[v[i]] = i;
	}
}

template <typename Ver, typename Edge>
template <typename ResultContainer>
bool Graph<Ver,Edge>::Tarjan(ResultContainer& result) const{
	if (!isDirected){
		std::cout << "The Graph isn't directed graph!\n";
		return 0;
	}
	vector<int> dfn(size), low(size);
	vector<bool> instack(size, 0);
	stack<int> st;
	result.clear();
	int index = 0;
	for (int i = 0 ; i < size ; ++ i){
		if (!dfn[i])
			Tarjandfs(i, index, dfn, low, instack, st, result);
	}
	return 1;
}

template <typename Ver, typename Edge>
template <typename PosContainer, typename FlagContainer, typename StackContainer, typename ResultContainer>
void Graph<Ver, Edge>::Tarjandfs(int x, int& index, PosContainer& dfn, PosContainer& low, FlagContainer& instack,
								StackContainer& st, ResultContainer& result) const{
	dfn[x] = low[x] = ++index;
	st.push(x);
	instack[x] = 1;
	for (node* p = edges[x]; p ; p = p->next){
		if (!dfn[p->v]){
			Tarjandfs(p->v, index, dfn, low, instack, st, result);
			low[x] = std::min(low[x], low[p->v]);
		}
		else if (instack[p->v]){
			low[x] = std::min(low[x], low[p->v]);
		}
	}

	if (dfn[x] == low[x]){
		int rsize = static_cast<int>(result.size());
		result.resize(rsize + 1);
		while (1){
			int t = st.top(); st.pop();
			instack[t] = 0;
			result[rsize].push_back(vertics[t]);
			if (t == x) break;
		}
	}
}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::eraseEdge(const Ver& a, const Ver& b){
	if (!(verToPos.count(a) && verToPos.count(b))){
		std::cout << "The two aren't all the vertics.\n";
		return 0;
	}
	int x = verToPos[a], y = verToPos[b], flag = 0;
	node* p = edges[x], *q = p;
	while (p){
		if (p->v == y){
			flag = 1;
			break;
		}
		q = p;
		p = p->next;
	}
	if (flag){
		if(p == q){
			edges[x] = p->next;
			delete p;
		}
		else {
			q->next = p->next;
			delete p;
		}
		if (!isDirected){
			q = p = edges[y];
			while (p){
				if (p->v == x)
					break;
				q = p;
				p = p->next;
			}
			if (p == q){
				edges[y] = p->next;
			}
			else q->next = p->next;
			delete p;
		}
		return 1;
	}
	return 0;
}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::addEdge(const Ver& a, const Ver& b, const Edge& e){
	if (!(verToPos.count(a) && verToPos.count(b))){
		std::cout << "The two aren't all the vertics.\n";
		return 0;
	}
	if (e == noEdge){
		std::cout << "Your can't add edge weigted infinity.\n";
		return 0;
	}
	int x = verToPos[a], y = verToPos[b];

	edges[x] = new node(y, e, edges[x]);

	if (!isDirected){
		edges[y] = new node(x, e, edges[y]);
	}
	return 1;
}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::exist(const Ver& a, const Ver& b) const{
	if (!(verToPos.count(a) && verToPos.count(b))){
		std::cout << "The two aren't all the vertics.\n";
		return 0;
	}
	int x = verToPos.find(a)->second, y = verToPos.find(b)->second;
	node* p = edges[x];
	while (p){
		if (p->v == y)
			return 1;
		p = p->next;
	}
	return 0;
}

template <typename Ver, typename Edge>
Edge Graph<Ver, Edge>::find(const Ver& a, const Ver& b) const{
	if (!(verToPos.count(a) && verToPos.count(b))){
		return noEdge;
	}
	int x = verToPos.find(a)->second, y = verToPos.find(b)->second;
	node* p = edges[x];
	while (p){
		if (p->v == y)
			return p->w;
		p = p->next;
	}
	return noEdge;
}

#endif // Graph_H
