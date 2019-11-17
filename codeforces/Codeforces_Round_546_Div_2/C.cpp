#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	// your code goes here
	int i,j,n,m;
	int ans = 1;

	cin >> n >> m;
	int nDiagnoals = n + m - 1;
	vector<int> diagonalsA[nDiagnoals];
	vector<int> diagonalsB[nDiagnoals];

	int matrixA[n][m];
	int matrixB[n][m];

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> matrixA[i][j];
			diagonalsA[i+j].push_back(matrixA[i][j]);
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> matrixB[i][j];
			diagonalsB[i+j].push_back(matrixB[i][j]);
		}
	}

	for(i=0;i<nDiagnoals;i++){
		sort(diagonalsA[i].begin(),diagonalsA[i].end());
		sort(diagonalsB[i].begin(),diagonalsB[i].end());
	}

	for(i=0;i<nDiagnoals;i++){
		for(j=0;j<diagonalsA[i].size();j++){
			if(diagonalsA[i][j] != diagonalsB[i][j]){
				ans = -1;
				break;
			}
		}
		if(ans == -1)
			break;
	}
	if(ans == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	
	//cout << ans << endl;

	return 0;
}
