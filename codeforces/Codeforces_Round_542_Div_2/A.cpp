#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n;
	cin >> n;
	int array[n];

	int temp, npos=0, nneg=0,nzer=0;
	for(i=0;i<n;i++){
		cin >> temp;
		if(temp>0)
			npos++;
		else if(temp<0)
			nneg++;
		else
			nzer++;
	}

	if(npos >= (n+1)/2){
		cout << 1 << endl;
	}
	else if(nneg >= (n+1)/2){
		cout << -1 << endl;
	}
	else{
		cout << 0 << endl;
	}

	return 0;
}
