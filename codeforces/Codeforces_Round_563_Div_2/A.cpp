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
	m = 2*n;
	vector<int> array(m);
	for(i=0;i<m;i++){
		cin >> array[i];
	}
	sort(array.begin(), array.end());

	long long int sum1=0,sum2=0;
	for(i=0;i<n;i++){
		sum1+=array[i];
	}

	for(i=n;i<m;i++){
		sum2+=array[i];
	}
	if(sum1==sum2)
		cout << "-1" << endl;
	else{
		for(i=0;i<m;i++){
			cout << array[i] << " ";
		}
	}
	
	return 0;
}