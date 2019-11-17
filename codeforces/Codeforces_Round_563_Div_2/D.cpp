#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i=0,x;

	cin >> n >> x;
	int m = pow(2,n);

	int size = 0;

	if(x>=m){
		size = 2*(n) - 1;
	}
	else{
		size = 2*(n-1) - 1;
	}

	int temp = x;
	while(temp!=0){
		//cout << temp << " " << endl;
		if((temp & 1) == 1){
			break;
		}
		temp = temp >> 1;
		i++;
	}
	//cout << i << endl;
	int exclude = pow(2,i);
	int array[size];
	if(x>=m){
		int ctr = 0;
		for(i=0;i<n;i++){
			array[ctr] = pow(2,i);
			array[size-ctr-1] = pow(2,i);
			ctr++;
		}
	}
	else{
		int ctr=0;
		for(i=0;i<n;i++){
			int cur = pow(2,i);
			//cout << cur << " yo " << exclude << " " << pow(2,i) <<  endl;
			if(cur==exclude)
				continue;
			array[ctr] = cur;
			array[size-ctr-1] = cur;
			ctr++;
		}
	}
	if(size < 0)
		size = 0;
	cout << size << endl;
	for(i=0;i<size;i++){
		cout << array[i] << " " ;
	}

	return 0;
}