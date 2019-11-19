#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,j,m,h,ans=1;
	cin >> n;
	int value[n];
	int cost[n];
	for(i=0;i<n;i++){
		cin >> value[i];
	}
	for(i=0;i<n;i++){
		cin >> cost[i];
	}
	int ans = 0;
	for(i=0;i<n;i++){
		if(value[i]>cost[i]){
			ans = ans + value[i] - cost[i];
		}
	}
	cout << ans << endl;
		
	return 0;
}