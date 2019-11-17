#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,ans=0,i;
	string initialString, firstStringResult, secondStringResult, thirdStringResult;
	cin >> n;
	int array[n];
	for(i=0;i<n;i++){
		cin >> array[i];
	}

	for(i=1;i<n;i++){
		if(array[i-1]==1){
			if(array[i] == 3)
				ans+=4;
			else{
				if(i>1 && array[i-2]==3){
					ans+=2;
				}
				else
					ans+=3;
			}
		}
		else if(array[i-1]==2){
			if(array[i]==1)
				ans+=3;
			else
				ans=-1;
		}
		else{
			if(array[i] == 1)
				ans+=4;
			else
				ans= -1;
		}
		if(ans==-1)
			break;
	}
	if(ans==-1)
		cout << "Infinite" << endl;
	else{
		cout << "Finite" << endl;
		cout << ans << endl;
	}
	return 0;
}
