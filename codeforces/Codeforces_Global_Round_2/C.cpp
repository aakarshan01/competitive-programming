#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,m,j;
	int currentScoreA = 0, currentScoreB = 0, nextScoreA, nextScoreB;
	cin >>n >>m;

	int matrixA[n][m];
	int matrixB[n][m];

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		    cin >> matrixA[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
		    cin >> matrixB[i][j];
		}
	}

	int mismatch = 0, ans = 1;
	for(i=0;i<n;i++){
		mismatch = 0;
		for(j=0;j<m;j++){
		    if(matrixA[i][j] != matrixB[i][j]){
		    	mismatch++;
		    }
		}
		if(mismatch %2 == 1){
			ans = 0;
			break;
		}
	}

	for(i=0;i<m;i++){
		mismatch = 0;
		for(j=0;j<n;j++){
		    if(matrixA[j][i] != matrixB[j][i]){
		    	mismatch++;
		    }
		}
		if(ans ==0 || mismatch %2 == 1){
			ans = 0;
			break;
		}
	}

	if(ans == 0){
		cout <<"No" << endl;
	}
	else
		cout << "Yes" << endl;

	return 0;
}
