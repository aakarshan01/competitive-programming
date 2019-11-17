#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,i;
	int array[n];
	for(i=0;i<n;i++)
		cin>>array[i];

	int firstNum = array[0];
	int firstNumIndex = 0, secondNumIndex = 1;
	int secondNum = array[1];


	for(i=1;i<n;i++){
		if(array[i] != firstNum){
			secondNum = array[i];
			secondNumIndex = i;
			break;
		}
	}

	int lastNum = array[n-1];
	int lastNumIndex = n-1, secondLastNumIndex = n-2;
	int secondLastNum = array[n-2];

	for(i=n-2;i>=0;i--){
		if(array[i] != lastNum){
			secondLastNum = array[i];
			secondLastNumIndex = i;
			break;
		}
	}	
	int ans = 0;
	if(firstNum != lastNum)
		ans = lastNumIndex - firstNumIndex;
	else{
		ans = max(secondLastNumIndex - firstNumIndex, lastNumIndex - secondNumIndex);
	}
	cout << ans << endl;
}
