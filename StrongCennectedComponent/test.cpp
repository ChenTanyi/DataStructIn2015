#include "Headers/Graph.h"

int main(){
	Graph<char,int> g(10, "ABCDEFGHIJ");
	g.addEdge('A', 'B', 1);g.addEdge('A', 'D', 1);
	g.addEdge('B', 'C', 1);g.addEdge('B', 'F', 1);
	g.addEdge('C', 'A', 1);g.addEdge('C', 'D', 1);g.addEdge('C', 'E', 1);
	g.addEdge('D', 'E', 1);
	g.addEdge('F', 'C', 1);
	g.addEdge('G', 'F', 1);g.addEdge('G', 'H', 1);
	g.addEdge('H', 'F', 1);g.addEdge('H', 'J', 1);
	g.addEdge('J', 'I', 1);
	g.addEdge('I', 'H', 1);
	vector< vector<char> > result;
	if (g.Tarjan(result)){
        for (int i = 0 ; i < static_cast<int>(result.size()) ; ++ i){
            for (int j = 0 ; j < static_cast<int>(result[i].size()) ; ++ j){
                std::cout << result[i][j] << " ";
            }
            std::cout << "\n";
        }
	}
    return 0;
}
