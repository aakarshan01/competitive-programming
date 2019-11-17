#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <iterator> 

using namespace std;

int main() {
	// your code goes here
	int i,j,n,m;
	cin >> n;
	int array[n];

	for(i=0;i<n;i++){
		cin >> array[i];
	}

	int k = 0, temp;
	int minTillNow = 1000000000;
	for(i=0;i<n;i++){
		if(i!=0){
			j = 0;
			temp=min(array[i],array[j])/ abs(i-j);
			minTillNow=min(temp,minTillNow);
		}
		if(i!=n-1){
			j = n-1;
			temp = min(array[i],array[j]) / abs(i-j);
			minTillNow=min(temp,minTillNow);
		}
	}
	k = max(k,minTillNow);
	
	cout << k << endl;

	return 0;
}