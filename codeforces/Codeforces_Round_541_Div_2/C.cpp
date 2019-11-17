#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n;
	int currentScoreA = 0, currentScoreB = 0, nextScoreA, nextScoreB;


	cin >> n;
	vector <int> inputArray(n);
	vector <int> ans(n);
	for(i=0;i<n;i++){
		cin >> inputArray[i];
	}
	sort(inputArray.begin(), inputArray.end());

	int lower = 0;
	int higher = n - 1;
	for(i=0;i<n;i++){
		if(i%2==0)
			ans[lower++] = inputArray[i];
		else
			ans[higher--] = inputArray[i];
	}

	for(i=0;i<n;i++){
		cout << ans[i] << " ";
	}

	return 0;
}
