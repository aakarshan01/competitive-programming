#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// your code goes here
	
	int i,j,n,m;

	cin >> n >> m;

	vector<long long int> boys(n);
	vector<long long int> girls(m);
	long long int ans = 0;
	for(i=0;i<n;i++){
		cin >> boys[i];
		ans = ans+boys[i];
	}
	for(i=0;i<m;i++){
		cin >> girls[i];
	}

	sort(boys.begin(), boys.end(), greater<long long int>());
	sort(girls.begin(), girls.end(),greater<long long int>());
	
	int temp = 1,row = 0,firstTaken = 0;
	for(i=0;i<m;i++){

		if(firstTaken==0 && boys[row] == girls[i]){
			firstTaken = 1;
			temp--;
		}
		else{
			ans += girls[i];
		}

		temp++;
		if(i+1<m&& firstTaken==0 && boys[row] == girls[i+1]){

		}
		else if(temp==m){
			temp=1;
			row++;
			firstTaken = 0;
		}
		
		//cout << " ans = " << ans << " row = " << row << " temp = " << temp <<endl;
	}
	for(i=row;i<n;i++){
		if(i==row){
			ans+=(m-temp)*boys[i];
		}
		else{
			ans+=(m-1)*boys[i];
		}

	}

	if(boys[0] > girls[m-1])
		ans = -1;
	cout << ans << endl;
	return 0;
}