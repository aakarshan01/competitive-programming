#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int i,j,n=-1,m=-1,k;
	cin >> k;
	string ans="";

	for(i=1;i*i<=k;i++){
		if(k%i==0){
			//cout << i ;
			if(k/i==i){
				if(i>=5){
					n = i;
					m = k / i;
					break;
				}
			}
			else{
				if(i>=5 && ((k/i) >= 5)){
					n = i;
					m = k / i;
					break;
				}
			}
		}
	}
	//cout << " n = " << n  << " m = " << m << endl;
	if(n==-1)
		cout << -1 << endl;
	else{
		char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
		char matrix[n][m];
		for(i=0;i<m;i++){
			matrix[0][i] = vowels[i%5];
			//cout << matrix[0][i] << " ";
			//ans = ans + matrix[0][i];
		}
		//cout << endl;
		for(i=1;i<5;i++){
			for(j=0;j<5;j++){
				matrix[i][j] = matrix[i-1][(j-1+5)%5];
				//cout << (j-1)%m << " ";
				//cout << matrix[i][j] << " " ;
				//ans = ans + matrix[i][j];
			}
			//cout << endl;
		}
		for(i=5;i<n;i++){
			for(j=0;j<m;j++){
				matrix[i][j] = vowels[j%5];
			}
		}
		for(i=5;i<m;i++){
			for(j=0;j<n;j++){
				matrix[j][i] = vowels[j%5];
			}
		}



		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				//cout << matrix[i][j] << " ";
				ans = ans + matrix[i][j];
			}
			//cout << endl;
		}

		cout << ans << endl;
	}

	return 0;
}