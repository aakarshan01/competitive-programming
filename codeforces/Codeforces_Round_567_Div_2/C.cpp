#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
map <int,int>m;

int main() {
	// your code goes here
	
	register int i,j;
	long long int ans = 0;
	int n,m;
	cin >> n >> m;
	char input[n][m];
	pair<int,int> matrix[n][m];
	pair<char,pair<char,char>>data[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> input[i][j];
		}
	}

	int ctr[3];
	ctr[0]=1;
	ctr[1]=0;
	ctr[2]=0;
	char db[3];
	int current = 0;

	for(j=0;j<m;j++){
		char currentChar = input[0][j]; 
		db[current] = currentChar;
		for(i=1;i<n;i++){
			if(input[i][j]==currentChar){
				ctr[current]++;
			}
			else{
				current=(current+1)%3;
				ctr[current]=1;
				currentChar = input[i][j];
				db[current] = currentChar;
			}
			int firstIndex = (current+1)%3;
			int secondIndex = (current+2)%3;
			int thirdIndex = current;
			int third = ctr[current];
			int first = ctr[(current+1)%3];
			int second = ctr[(current+2)%3];
			//cout << first << second << third<<endl;
			if(first>=second && second == third && second > 0){
				int prevCol = 0;
				//cout << " i = " << i  << " j = " << j << "matrix[i][j-1].first = " <<matrix[i][j-1].first << " matrix[i][j-1].second = " << matrix[i][j-1].second << " currentFlagL = "<< ctr[second]<<endl;
				if(j>0 && matrix[i][j-1].first>0 && matrix[i][j-1].second == ctr[secondIndex]){
					//cout << " i = " << i << " j = " << j << " db[firstIndex] = " << db[firstIndex] << " db[secondIndex] = " << db[secondIndex] << " db[thirdIndex] = " << db[thirdIndex] << endl; 
					//cout << " i = " << i << " j = " << j << " data[i][j-1].first = " << data[i][j-1].first << " data[i][j-1].second.first = " << data[i][j-1].second.first << " data[i][j-1].second.second = " << data[i][j-1].second.second << endl; 
					if(data[i][j-1].first == db[firstIndex] && data[i][j-1].second.first == db[secondIndex] && data[i][j-1].second.second == db[thirdIndex])
						prevCol = matrix[i][j-1].first;
				}
				matrix[i][j] = make_pair(prevCol+1,ctr[secondIndex]);
				data[i][j] = make_pair(db[firstIndex],make_pair(db[secondIndex],db[thirdIndex]));
				ans+=prevCol+1;
			}
			else{
				matrix[i][j] = make_pair(0,0);
			}
		}
		ctr[0]=1;
		ctr[1]=0;
		ctr[2]=0;
		db[1] = '1';
		db[2] = '2';
		current=0;	
	}
	/*
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cout << matrix[i][j].first << "" ;
		}
		cout << endl;
	}*/
	cout << ans << endl;
	return 0;
}