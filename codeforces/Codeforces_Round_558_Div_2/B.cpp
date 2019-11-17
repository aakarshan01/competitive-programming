#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int i,j,n,m;
	cin >> n >> m;
	int matrixA[n][m], matrixB[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> matrixA[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> matrixB[i][j];
			if(matrixA[i][j]>matrixB[i][j]){
				int temp = matrixA[i][j];
				matrixA[i][j] = matrixB[i][j];
				matrixB[i][j] = temp;
			}
		}
	}
	int valid = 1;
	for(i=0;i<n;i++){
		for(j=1;j<m;j++){
			if(matrixA[i][j] <= matrixA[i][j-1])
				valid=0;
		}
		if(valid==0)
			break;
	}
	for(j=0;j<m;j++){
		for(i=1;i<n;i++){
			if(matrixA[i][j] <= matrixA[i-1][j])
				valid=0;
		}
		if(valid==0)
			break;
	}
	for(i=0;i<n;i++){
		for(j=1;j<m;j++){
			if(matrixB[i][j] <= matrixB[i][j-1])
				valid=0;
		}
		if(valid==0)
			break;
	}
	for(j=0;j<m;j++){
		for(i=1;i<n;i++){
			if(matrixB[i][j] <= matrixB[i-1][j])
				valid=0;
		}
		if(valid==0)
			break;
	}

	if(valid==1)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;


	
	return 0;
}