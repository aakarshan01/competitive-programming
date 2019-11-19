#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,h;
	
	int ans = 1;

	cin >> n >> h;
	vector<int> array(n);
	
	for(i=0;i<n;i++){
		cin >> array[i];
	}
	int k =1, valid = 1;
	
	while(k<n){
		int tempHeight = h;

		//cout << "k = " << k << endl;
		sort(array.begin(), array.begin() + k + 1, greater<int>());

		/*for(i=0;i<=k;i++){
			cout << array[i] << " " ;
		}
		cout << endl;
		*/
		for(i=0;i<=k;){
			if(array[i] <= tempHeight){
				tempHeight = tempHeight - array[i];
				//cout << "tempHeight = "<< tempHeight << endl;
			}
			else{
				valid = 0;
				break;
			}
			i = i+2;
		}
		if(valid == 0){
			break;
		}
		k++;
	}

	cout << k << endl;

	return 0;
}
