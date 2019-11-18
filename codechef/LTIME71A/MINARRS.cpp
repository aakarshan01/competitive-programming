#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t,n,temp,d,i,j;
	int rowNo=0, colNo = 0;
	long ans = 0;
	cin >> t ;
	
	int possible = 1;
	while(t!=0){
		cin  >> n;
		int array[n];
		long long int sum = 0;
		for(i=0;i<n;i++){
			cin >> array[i];
			sum=sum+array[i];
		}

		int counter[32];
		int currentBit = 0;

		for(i=0;i<32;i++)
			counter[i] = 0;
		for(i=0;i<n;i++){
			temp = array[i];
			currentBit = 0;
			while(temp!=0){
				if(temp&1 == 1){
					counter[currentBit]++;
				}
				temp = temp / 2;
				currentBit++;
			}
			//for(j=31;j>=0;j--)
			//	cout << counter[j]<< " " ;
			//cout << endl;
		}
		
		int first=1;
		for(i=31;i>=0;i--){
			if(counter[i]==0 && first == 1)
				continue;
			else{
				first = 0;
				if(counter[i]>n-counter[i]){
					//int sub = (2*counter[i] - n);
					//cout << " sum = " << sum  << "sub = " << sub << endl;
					sum = sum - ((2.0*counter[i] - n) * pow(2,i));
				}
			}
		}
		cout << sum << endl;
		t--;
	}
	return 0;
}
	