#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,ans = -1;
	cin >> n;

	int parent[n];
	int noRespect[n];
	int kick[n];

	for(i=0;i<n;i++){
		cin >> parent[i] >> noRespect[i];
		parent[i]--;
		kick[i] = 1;
	}

	for(i=0;i<n;i++){
		if(noRespect[i] == 0){
			kick[i] = 0;
			kick[parent[i]] = 0;
		}
	}

	for(i=0;i<n;i++){
		if(kick[i] == 1){
			cout << i+1 << " ";
			ans = 1;
		}
	}
	//cout << endl;
	if(ans == -1){
		cout << -1 << endl;
	}
	else{
		cout << endl;
	}

	return 0;
}