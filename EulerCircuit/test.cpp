#include "Headers/Graph.h"
#include <iostream>

int main(){
    Graph<char, int> g(6, "abcdef", 0, -1);
    g.addEdge('a', 'b', 1);
    g.addEdge('a', 'c', 1);
    g.addEdge('b', 'c', 1);
    g.addEdge('b', 'd', 1);
    g.addEdge('b', 'e', 1);
    g.addEdge('c', 'd', 1);
    g.addEdge('c', 'e', 1);
    g.addEdge('d', 'e', 1);
    g.addEdge('d', 'f', 1);
    g.addEdge('e', 'f', 1);
    g.eulerCircuit('f');
    g.bfs();
    g.dfs();
    g.addEdge('a', 'f', 1);
    g.editEdge('a', 'b', 2);
    g.editEdge('b', 'c', -1);
    g.editEdge('a', 'e', 1);
    g.eulerCircuit('b');
    g.eraseEdge('a', 'f');
    g.eulerCircuit('c');
    return 0;
}
