#include <iostream>
#include "MaximumPlanarSubset.h"

using namespace std;

int main(int argc, char* argv[])
{
	int N = 0;
    fstream fin(argv[1]);
	fin >> N;
	
	int** M = new int*[N];
	int** S = new int*[N];
	int** calculated = new int*[N];
	for(int i = 0; i < N; i++){
		M[i] = new int[N];
		S[i] = new int[N];
		calculated[i] = new int[N];
	}
	int* chord = new int[N];
    int endpoint1, endpoint2;
	
    while(fin >> endpoint1 >> endpoint2){
		chord[endpoint1] = endpoint2;
		chord[endpoint2] = endpoint1;
	}
	fin.close();

	int max = findMaximumPlanarSubset(M, S, calculated, chord, 0, N - 1);
	
	fstream fout;
    fout.open(argv[2], ios::out);
	fout << max << endl;

	findNonOverlapeChord(S, 0, N - 1, fout);
	fout.close();
	return 0;
}