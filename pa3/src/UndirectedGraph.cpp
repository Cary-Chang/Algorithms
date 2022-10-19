#include "UndirectedGraph.h"
UndirectedGraph::UndirectedGraph(int V, int E){
	this->V = V;
	this->E = E;
}

void UndirectedGraph::addEdge(int u, int v, int w){
	edges.push_back(make_pair(w, make_pair(u, v))); 
}

void UndirectedGraph::cycleBreaking(list<pair<int, intPair> >& removedEdges, char type){
	int totalWeight = 0;
	DirectedGraph G(V, V - 1);
	DisjointSets dSet(V);
	
	sort(edges.begin(), edges.end(), greater<pair<int, intPair> >());
	vector<pair<int, intPair> >::iterator it;
	
	for(it = edges.begin(); it != edges.end(); it++){
		int u = it->second.first; 
        int v = it->second.second; 
		int w = it->first;
		if(dSet.findSet(u) != dSet.findSet(v)){
			dSet.unionSets(u, v);
			G.addEdge(u, v);
		}
		else{
			removedEdges.push_back(make_pair(w, make_pair(u, v)));
			totalWeight += w;
		}		
	}
	if(type == 'd'){
		list<pair<int, intPair> >::iterator it = removedEdges.begin();
		while(it != removedEdges.end()){
			int u = it->second.first; 
			int v = it->second.second; 
			int w = it->first;
			G.addEdge(u, v);
			it++;
			if(w <= 0)
				break;
			if(G.isCyclic())
				G.removeEdge(u, v);				
			else{
				removedEdges.remove(make_pair(w, make_pair(u, v)));
				totalWeight -= w;
			}
		}
	}
	removedEdges.push_back(make_pair(totalWeight, make_pair(0, 0)));
}
