#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
map <int,int>m;

int main() {
	// your code goes here
	
	int i,j,n;
	cin >> n;
	int array[n];
	
	for(i=0;i<n;i++){
		cin >> array[i];
	}

	int start1 = 0, start2 = -1, start3 = -1, start4 = -1, start5 = -1, start6 = -1;

	vector<int> answer[n];
	int full=0;
	for(i=0;i<n;i++){
		if(array[i] == 4){
			answer[start1].push_back(4);
			start1++;
			if(start2 == -1)
				start2++;
		}
		else if(array[i] == 8){
			if(start2!=-1 && start2<start1){
				answer[start2].push_back(8);
				start2++;
				if(start3 == -1)
					start3++;
			}
		}
		else if(array[i] == 15){
			if(start3!=-1 && start3 < start2){
				answer[start3].push_back(15);
				start3++;
				if(start4==-1)
					start4++;
			}
		}
		else if(array[i] == 16){
			if(start4!=-1 && start4 < start3){
				answer[start4].push_back(16);
				start4++;
				if(start5==-1)
					start5++;
			}
		}
		else if(array[i] == 23){
			if(start5!=-1 && start5 < start4){
				answer[start5].push_back(16);
				start5++;
				if(start6==-1)
					start6++;
			}
		}
		else if(array[i] == 42){
			if(start6!=-1 && start6 < start5){
				answer[start6].push_back(42);
				start6++;
				full++;
			}
		}
	}
	//cout << start1 << start2 << start3 << start4 << start5 << start6 << endl;

	int ans = n - 6 * full;
	cout << ans << endl;

	return 0;
}