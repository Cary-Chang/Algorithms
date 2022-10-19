#include "MaximumPlanarSubset.h"

int findMaximumPlanarSubset(int** M, int** S, int** calculated, int* chord, int i, int j){
	if(calculated[i][j] != 0)
		return M[i][j];
	if(i >= j){
		M[i][j] = 0;
		calculated[i][j] = 1;
	}
	else{
		int k = chord[j];
		if(k < i || k > j){
			M[i][j] = findMaximumPlanarSubset(M, S, calculated, chord, i, j - 1);
			calculated[i][j] = 1;
		}
		else if(k == i){
			M[i][j] = findMaximumPlanarSubset(M, S, calculated, chord, i + 1, j - 1) + 1;
			S[i][j] = k + 1;
			calculated[i][j] = 1;
		}
		else{
			int a = findMaximumPlanarSubset(M, S, calculated, chord, i, j - 1);
			int b = findMaximumPlanarSubset(M, S, calculated, chord, i, k - 1) + 1 + findMaximumPlanarSubset(M, S, calculated, chord, k + 1, j - 1);
			if(a >= b){
				M[i][j] = a;
				calculated[i][j] = 1;
			}
			else{
				M[i][j] = b;
				S[i][j] = k + 1;
				calculated[i][j] = 1;
			}
		}
	}
	return M[i][j];
}

void findNonOverlapeChord(int** S, int p, int r, fstream& fout){
	if(r > p){
		if(S[p][r] > 0){
			findNonOverlapeChord(S, p, S[p][r] - 2, fout);
			fout << S[p][r] - 1 << ' ' << r << endl;
			findNonOverlapeChord(S, S[p][r], r - 1, fout);			
		}
		else
			findNonOverlapeChord(S, p, r - 1, fout);
	}
}