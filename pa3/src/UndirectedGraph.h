#include <algorithm>
#include <vector> 
#include <list>
#include "DirectedGraph.h"
#include "DisjointSets.h"
#include <functional>   
using namespace std; 

typedef  pair<int, int> intPair; 

class UndirectedGraph{
	public:		
		UndirectedGraph(int V, int E);
		vector<pair<int, intPair> > edges; 	
		void addEdge(int u, int v, int w);
		void cycleBreaking(list<pair<int, intPair> >& removedEdges, char type);
	private:
		int V, E;
};