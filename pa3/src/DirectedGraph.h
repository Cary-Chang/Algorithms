#include <list>
using namespace std;
class DirectedGraph{
	public:		
		DirectedGraph(int V, int E);	
		void addEdge(int u, int v);
		bool isCyclic(); 
		void removeEdge(int u, int v);
	private:
		int V, E;
		list<int>* adj;
		bool DFS_Visit(int v, bool visited[], bool *Stack);
}; 