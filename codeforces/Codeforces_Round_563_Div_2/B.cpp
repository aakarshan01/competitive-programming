#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	int cnt=0,i,j,n,m,a,b,x,y1,y2=-1,y=-1;

	cin >> n;

	vector<int> array(n);
	for(i=0;i<n;i++){
		cin >> array[i];
		if(array[i]%2==1){
			cnt++;
		}
		//cout << a << b << endl;
	}
	if(cnt == 0 || cnt == n){

	}
	else{
		sort(array.begin(), array.end());
	}
	for(i=0;i<n;i++){
		cout << array[i] << " ";
	}
	
	return 0;
}