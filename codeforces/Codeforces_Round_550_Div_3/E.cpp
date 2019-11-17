#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,ans = -1;
	cin >> n;

	vector<int> array(n);
	for(i=0;i<n;i++)
		cin >> array[i];

	ans=1;
	int ni,nd=0;
	vector<int> increasing;
	vector<int> decreasing;

	sort(array.begin(), array.end());
	increasing.push_back(array[0]);
	int prev = array[0];
	array[0] = -1;
	ni = 1;
	for(i=1;i<n;i++){
		if(array[i] != prev){
			increasing.push_back(array[i]);
			prev = array[i];
			array[i] = -1;
			ni++;
		}
	}

	for(i=n-1;i>=0;i--){
		if(array[i]!=-1){
			decreasing.push_back(array[i]);
			nd++;
		}
	}
	if(decreasing.size() > 1){
		for(i=0;i<decreasing.size()-1;i++){
			if(decreasing[i] == decreasing[i+1])
				ans = -1;
		}
	}

	if(ans == -1){
		cout << "NO" << endl;
		return 0;
	}
	else{
		cout << "YES" << endl;
	}
	cout << ni << endl;
	for(i=0;i<ni;i++)
		cout << increasing[i] << " ";
	cout << endl << nd << endl; 
	for(i=0;i<nd;i++)
		cout << decreasing[i] << " ";
	cout << endl;

	return 0;
}