#include <iostream>   
#include <fstream>
#include "UndirectedGraph.h"
using namespace std; 

typedef  pair<int, int> intPair; 

int main(int argc, char* argv[]){
	char type;
	int V, E;
	int u, v, w;
	list<pair<int, intPair> > removedEdges;
	fstream fin(argv[1]);
	
	fin >> type; 
	fin >> V; 
	fin >> E;

	UndirectedGraph G(V, E);
	G.edges.reserve(E);
	while(fin >> u >> v >> w)
		G.addEdge(u, v, w);
	fin.close();

	G.cycleBreaking(removedEdges, type);

	fstream fout;
    fout.open(argv[2], ios::out);
	fout << removedEdges.back().first << endl;
	removedEdges.pop_back();
	
	list<pair<int, intPair> >::iterator it;	
	for(it = removedEdges.begin(); it != removedEdges.end(); it++)
		fout << it->second.first << ' ' << it->second.second << ' ' << it->first << endl;
	fout.close();
	return 0;
}