#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,temp;
	long long int ans = 0;

	cin >> n;
	int firstSet[n];
	int secondSet[n];

	for(i=0;i<n;i++){
		firstSet[i] = -1;
		secondSet[i] = -1;
	}

	for(i=0;i<2*n;i++){
		cin >> temp;
		temp--;
		if(firstSet[temp] == -1)
			firstSet[temp] = i;
		else
			secondSet[temp] = i;
	}

	int currentPositionA = 0;
	int currentPositionB = 0;

	for(i=0;i<n;i++){
		int temp1 = abs(firstSet[i] - currentPositionA) + abs(secondSet[i] - currentPositionB);
		int temp2 = abs(firstSet[i] - currentPositionB) + abs(secondSet[i] - currentPositionA);

		if(temp1 < temp2){
			ans += temp1;
			currentPositionA = firstSet[i];
			currentPositionB = secondSet[i];
	    }
	    else{
	    	ans+= temp2;
	    	currentPositionB = firstSet[i];
	    	currentPositionA = secondSet[i];
	    }
	}
	cout << ans << endl;

	return 0;
}