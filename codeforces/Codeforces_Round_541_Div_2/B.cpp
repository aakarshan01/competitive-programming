#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n;
	int currentScoreA = 0, currentScoreB = 0, nextScoreA, nextScoreB;

	int ans = 1;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> nextScoreA >> nextScoreB;

		if(nextScoreA == currentScoreA && nextScoreB == currentScoreB){

		}
		else {
			int tempMin = min(nextScoreA, nextScoreB);
			int tempMax = max(currentScoreA, currentScoreB);
			int temp = tempMin - tempMax;
			if(temp >= 0){
				if(temp==0 && tempMin == currentScoreA && tempMin == currentScoreB)
					temp = 0;
				else if(temp==0 && i > 0)
					temp = 1;
				if(tempMin != tempMax && i > 0 && currentScoreA != currentScoreB)
					temp = temp + 1;
				ans = ans + temp;
			}
		}
		currentScoreA = nextScoreA;
		currentScoreB = nextScoreB;

		//cout << ans << endl;
	}
	cout << ans << endl;

	return 0;
}
