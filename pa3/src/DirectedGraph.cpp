#include "DirectedGraph.h"
DirectedGraph::DirectedGraph(int V, int E){
	this->V = V;
	this->E = E;
	adj = new list<int>[V];
}

void DirectedGraph::addEdge(int u, int v){
	adj[u].push_back(v);
}

void DirectedGraph::removeEdge(int u, int v){
	adj[u].remove(v);
}

bool DirectedGraph::isCyclic(){
	bool *visited = new bool[V](); 
    bool *Stack = new bool[V](); 
    for(int i = 0; i < V; i++){ 
        if (DFS_Visit(i, visited, Stack)) 
            return true;  
	}
    return false;
}

bool DirectedGraph::DFS_Visit(int v, bool visited[], bool *Stack){
	if(visited[v] == false){ 
        visited[v] = true; 
        Stack[v] = true;   
        list<int>::iterator it; 
        for(it = adj[v].begin(); it != adj[v].end(); it++){ 
            if(!visited[*it] && DFS_Visit(*it, visited, Stack)) 
                return true; 
            else if(Stack[*it]) 
                return true; 
        }   
    } 
    Stack[v] = false;  
    return false;
}