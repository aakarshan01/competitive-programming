#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define SIZE 2002
int mod = 1000000007;

bool isValid(vector<vector<char> > &matrix, int n){

	int i,j,k,l;
	for(i=1;i<n;i++){
		for(j=1;j<n;j++){
			if(matrix[i][j]=='.')
				continue;
			//cout << i << " yo " << j << endl;
			for(k=i+1;k<n;k++){
				for(l=j+1;l<n;l++){
					//cout << k << " yo " << l << endl;
					if(matrix[i][j]=='O' && matrix[i][l] == 'O' && matrix[k][j] == 'O' && matrix[k][l]=='O'){
						cout << " i = " << i << " j = " << j << " k = " << k << " l = " << l << endl;
						return false;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	// your code goes here
	int t,j, n, k, i,r,c,m;
	long ans = 0;

	cin >> t;
	while(t!=0){
		ans=0;
		cin >> n;
		map<int,int> m; 
		int terms=0;
		int a = 2,d=2,prevd=1;
		int temp = a;
		vector<vector<char>> matrix(n+1);

		while(temp <= 2*n){
			m[temp] = 1;
			temp = temp + d;

			d = d + prevd;
		}
		//for(i=0;i<size;i++)
		//	cout << series[i] << " " ;

		for(i=1;i<=n;i++){
			matrix[i] = vector<char>(n+1);
			for(j=1;j<=n;j++){
				if(m.find(i+j)!=m.end()){
					matrix[i][j] = 'O';
					ans++;
				}
				else{
					matrix[i][j] = '.';
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				cout << matrix[i][j];
			}
			cout << endl;
		}
		cout << "isValid = " << isValid(matrix, n+1) << " ans = " << ans << endl;
		t--;
	}
	return 0;
}
	