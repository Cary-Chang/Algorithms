#include "DisjointSets.h"
DisjointSets::DisjointSets(int n){
	this->n = n; 
    parent = new int[n + 1]; 
    rank = new int[n + 1](); 

    for(int i = 0; i <= n; i++) 
        parent[i] = i;  
}

int DisjointSets::findSet(int u){
	if (u != parent[u]) 
        parent[u] = findSet(parent[u]); 
    return parent[u]; 
}

void DisjointSets::unionSets(int x, int y){
	x = findSet(x);
	y = findSet(y);
	if(rank[x] > rank[y])
		parent[y] = x;
	else{
		parent[x] = y;
		if(rank[x] == rank[y])
			rank[y]++;
	}
}