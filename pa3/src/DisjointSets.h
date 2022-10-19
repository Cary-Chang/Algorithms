using namespace std;
class DisjointSets{
	public:
		DisjointSets(int n);
		int findSet(int u);
		void unionSets(int x, int y);
	private:	
		int *parent, *rank;
		int n;	
};