#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t,n,d,i,j;
	int rowNo=0, colNo = 0;
	long ans = 0;
	cin >> t ;
	
	int possible = 1;
	while(t!=0){
		cin >> n >> d;
		vector<int> array(n);
		
		for(i=0;i<n;i++){
			cin >> array[i];
		}
		sort(array.begin() + 1, array.end());
		
		int current = array[0], bigger = current, smaller = current;
		
		if(array[n-1] > bigger)
			bigger = array[n-1];
		if(array[1] < smaller)
			smaller = array[1];

		for(i=1;i<n-1;i++){
			if(array[i] < current && array[i+1] > current){
				break;
			}
		}


		int pos1 = 1, pos2 = 1;
		
		for(j=1;j<n-1;j++){
			if(array[j+1]-array[j] > d){
				pos1 = 0;
				break;
			}
		}

		if(n==2){
			if(abs(array[1]- array[0]) <= d)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else if(array[0] == bigger || array[0] == smaller){
			//cout << "2 nd case" << endl;
			if(pos1==1){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
		else{
			//cout << "3 rd case" << endl;
			if(bigger - array[i] > d && array[i+1] - smaller > d)
				pos2 = 0;
			if(pos1==1 && pos2 == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}


		t--;
	}
	return 0;
}
	