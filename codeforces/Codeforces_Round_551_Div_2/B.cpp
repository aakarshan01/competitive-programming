#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,j,m,h;
	cin >> n >> m >> h;
	int front[m];
	int left[n];
	int top[n][m];
	int answer[n][m];

	for(i=0;i<m;i++)
		cin >> front[i];
	for(i=0;i<n;i++)
		cin >> left[i];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> top[i][j];
			answer[i][j] = top[i][j];
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(top[i][j] > 0){
				answer[i][j] = min(left[i], front[j]);
			}
		}
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}