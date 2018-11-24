#ifndef Graph_H
#define Graph_H

#include "vector.h"
#include <map>

template <typename Ver, typename Edge>
class Graph{
private:
    struct EulerNode{
		int value;
		EulerNode* next;
		EulerNode(const int& v = Ver(), EulerNode* nxt = 0):value(v), next(nxt){}
		EulerNode(const EulerNode& x):value(x.value), next(x.next){}
	};
public:
	Graph(int, const Ver*, bool = 1, const Edge& = Edge());
	~Graph(){}
	void bfs() const;
	void dfs() const;
	bool eulerCircuit(const Ver&) const;
	bool eraseEdge(const Ver&, const Ver&);
	bool addEdge(const Ver&, const Ver&, const Edge&);
	bool editEdge(const Ver&, const Ver&, const Edge&);
	bool exist(const Ver&, const Ver&) const;
	Edge find(const Ver&, const Ver&) const;

private:
	const int size;
	const Edge noEdge;
	const bool isDirected;
	vector<Ver> vertics;
	vector< vector<Edge> > edges;
	std::map<Ver, int> verToPos;

	template <typename FlagContainer>
	void dfs(int, FlagContainer&) const;

	bool eulerCircuit(int, vector< vector<Edge> >&, EulerNode*&, EulerNode*&, vector<int>&, vector<int>&) const;

};


template <typename Ver, typename Edge>
Graph<Ver, Edge>::Graph(int verSize, const Ver* v, bool directed, const Edge& none)
	:size(verSize), noEdge(none), isDirected(directed), vertics(v, v + verSize), edges(verSize, vector<Edge>(verSize, noEdge)){
	for (int i = 0 ; i < size ; ++ i){
		verToPos[v[i]] = i;
	}
}

template <typename Ver, typename Edge>
void Graph<Ver, Edge>::bfs() const{//BFS for traversal the graph, time complexity is O(N^2)
	vector<bool> visit(size, 0);
	vector<int> queue;
	std::cout << "The Breadth-First Search Traversal sequence is : ";
	for (int i = 0 ; i < size; ++ i){
		if (!visit[i]){
			visit[i] = 1;
			queue.clear();
			queue.push_back(i);
			for (int head = 0; head < static_cast<int>(queue.size()) ; ++ head){
				int now = head;
				std::cout << vertics[now] << "\t";
				for (int j = 0 ; j < size ; ++ j){
					if (edges[now][j] != noEdge && !visit[j]){
						queue.push_back(j);
						visit[j] = 1;
					}
				}
			}
		}
	}
	std::cout << "\n";
}

template <typename Ver, typename Edge>
void Graph<Ver, Edge>::dfs() const{//DFS for traversal the graph, time complexity is O(N^2)
	vector<bool> visit(size, 0);
	std::cout << "The Depth-First Search Traversal sequence is : ";
	for (int i = 0; i < size ; ++ i){
		if (!visit[i]){
			dfs(i, visit);
		}
	}
	std::cout << "\n";
}

template <typename Ver, typename Edge>
template <typename FlagContainer>
void Graph<Ver, Edge>::dfs(int now, FlagContainer& visit) const{
	visit[now] = 1;
	std::cout << vertics[now] << "\t";
	for (int i = 0 ; i < size ; ++ i){
		if (edges[now][i] != noEdge && !visit[i])
			dfs(i, visit);
	}
}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::eulerCircuit(const Ver& start) const{
	vector<int> outDegree(size, 0), inDegree(size, 0);

	int s = 0;
	if (!verToPos.count(start)){
		std::cout << "Start node does not exist.\n";
		return 0;
	}
	else s = verToPos.find(start)->second;

	for (int i = 0 ; i < size ; ++ i){
		for (int j = 0 ; j < size ; ++ j)
			if (edges[i][j] != noEdge)
				++ outDegree[i], ++ inDegree[j];
	}
	for (int i = 0 ; i < size ; ++ i){
        if (isDirected){
            if (outDegree[i] != inDegree[i]){
                std::cout << "There is none Euler circuit in the graph.\n";
                return 0;
            }
        }
        else {
            if (outDegree[i] & 1){
                std::cout << "There is none Euler circuit in the graph.\n";
                return 0;
            }
        }
	}

	vector< vector<Edge> > tmpedge = edges;

	EulerNode *head, *tail;
	if (!eulerCircuit(s, tmpedge, head, tail, inDegree, outDegree)){
		std::cout << "There is none Euler circuit in the graph.\n";
		return 0;
	}
	EulerNode* p = head;
	while (p){
		int now = p->value;
		if (outDegree[now]){
			EulerNode *begin, *end;
			if (eulerCircuit(now, tmpedge, begin, end, inDegree, outDegree)){
				end->next = p->next;
				p->next = begin->next;
				delete begin;
			}
			else {
				std::cout << "There is none Euler circuit in the graph.\n";
				while (head){
					p = head; head = head->next;
					delete p;
				}
				return 0;
			}
		}
		p = p->next;
	}

	std::cout << "The Euler circuit is : ";
	while (head){
		std::cout << vertics[head->value] << "\t";
		p = head; head = head->next;
		delete p;
	}
	std::cout << "\n";
	return 1;

}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::eulerCircuit(int s, vector< vector<Edge> >& edge, Graph<Ver, Edge>::EulerNode*& begin,
									Graph<Ver, Edge>::EulerNode*& end, vector<int>& inDegree, vector<int>& outDegree) const{
	begin = end = new EulerNode(s);
	int now = s;
	while (outDegree[s]){
		int next;
		for (next = 0 ; next < size && edge[now][next] == noEdge ; ++ next);
		if (next == size){
			while (begin){
				EulerNode* p = begin; begin = begin->next;
				delete p;
			}
			end = 0;
			return 0;
		}
		end->next = new EulerNode(next);
		end = end->next;
		-- outDegree[now];
		-- inDegree[next];
		edge[now][next] = noEdge;
		if (!isDirected){
			-- inDegree[now];
			-- outDegree[next];
			edge[next][now] = noEdge;
		}
		now = next;
	}
	return 1;
}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::eraseEdge(const Ver& a, const Ver& b){
	if (!(verToPos.count(a) && verToPos.count(b))){
		std::cout << "The two aren't all the vertics.\n";
		return 0;
	}
	int x = verToPos[a], y = verToPos[b];
	if (edges[x][y] == noEdge){
		std::cout << "There is no edge between these two vertics.\n";
		return 0;
	}

	edges[x][y] = noEdge;
	if (!isDirected){
		edges[y][x] = noEdge;
	}
	return 1;
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
	if (edges[x][y] != noEdge){
		std::cout << "There has been an edge between these two vertics.\n";
		return 0;
	}

	edges[x][y] = e;
	if (!isDirected){
		edges[y][x] = e;
	}
	return 1;
}

template <typename Ver, typename Edge>
bool Graph<Ver, Edge>::editEdge(const Ver& a, const Ver& b, const Edge& e){
	if (!(verToPos.count(a) && verToPos.count(b))){
		std::cout << "The two aren't all the vertics.\n";
		return 0;
	}
	if (e == noEdge){
		std::cout << "Your can't edit edge weigted infinity.\n";
		return 0;
	}
	int x = verToPos[a], y = verToPos[b];
	if (edges[x][y] == noEdge){
		std::cout << "There hasn't been an edge between these two vertics.\n";
		return 0;
	}

	edges[x][y] = e;
	if (!isDirected){
		edges[y][x] = e;
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
	if (edges[x][y] == noEdge) return 0;
	return 1;
}

template <typename Ver, typename Edge>
Edge Graph<Ver, Edge>::find(const Ver& a, const Ver& b) const{
	if (!(verToPos.count(a) && verToPos.count(b))){
		return noEdge;
	}
	int x = verToPos.find(a)->second, y = verToPos.find(b)->second;
	return edges[x][y];
}

#endif // Graph_H
