#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,j,m,h,ans=1;
	cin >> n >> m;
	int matrix[n][m];
	set<int> unique[n];
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>matrix[i][j];
			unique[i].insert(matrix[i][j]);
		}
	}

	int uniqueRow = -1;
	for(i=0;i<n;i++){
		//cout << "i = " << i << " size = " << unique[i].size() << endl;
		if(unique[i].size()>1){
			uniqueRow = i;
			break;
		}
	}
	if(uniqueRow==-1){
		int xor1 = 0;
		int answer[n];
		for(i=0;i<n;i++){
			answer[i] = *(unique[i].begin());
			xor1 = xor1^answer[i];
		}
		if(xor1 == 0){
			cout << "NIE" << endl;
		}
		else{
			cout << "TAK" << endl;
			for(i=0;i<n;i++){
				cout << 1 << " ";
			}
		}
	}
	else{
		cout << "TAK" << endl;
		int xor1 = 0;
		int answer[n];
		int ans[n];
		for(i=0;i<n;i++){
			if(i!=uniqueRow){
				answer[i] = *(unique[i].begin());
				cout << answer[i] << endl;
				xor1 = xor1^answer[i];
				ans[i] = 1;
			}
		}
		
		for(i=0;i<m;i++){
			int temp = matrix[uniqueRow][i];
			//cout << xor1 << " " << temp <<  " " << (xor1^temp) << " m =  " << m << endl;
			if( (xor1^temp) > 0){

				answer[uniqueRow] = temp;
				ans[uniqueRow] = i + 1;
				break;
			}
		}
		for(i=0;i<n;i++){
			cout << ans[i] << " ";
		}
	}
	
	return 0;
}