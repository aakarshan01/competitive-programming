#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define SIZE 2002
int mod = 1000000007;

int main() {
	// your code goes here
	long long int t,n,k,x;
	register int i;
	cin >> t;

	while(t!=0){
		cin >> n;

		long long int inputArray[n];
		long long int xorArray[n];
		long long int ans = 0;
		for(i=0;i<n;i++){
			cin>>inputArray[i];	
			ans+=inputArray[i];
		}
		//cout <<"yo0"<<endl;
		cin >> k >> x;
		for(i=0;i<n;i++){
			xorArray[i] = inputArray[i]^x;
			//cout << xorArray[i] << " ";
		}
		//cout<<"yo1"<< endl;
		vector<long long int>profit(n);
		for(i=0;i<n;i++){
			profit[i] = xorArray[i] - inputArray[i];
		}
		sort(profit.begin(), profit.end(),greater<long long int>());
		//cout <<"yo2"<<endl;
		
		long long int temp=0;
		if(k==n){
			for(i=0;i<n;i++){
				temp+=profit[i];
			}
			if(temp>0)
				ans+=temp;
		}
		else if(k%2==1){
			for(i=0;i<n;i++){
				if(profit[i]>0){
					ans+=profit[i];
				}
				else{
					break;
				}
			}
		}
		else{
			int j=0,out=0;
			for(i=0;i<n;i++){
				if(profit[i]<0)
					break;
				temp+=profit[i];
			}
			if(i%2==1){
				if(i==n){
					temp-=profit[i-1];
				}
				else{
					if(profit[i]+profit[i-1]>0)
						temp+=profit[i];
					else
						temp-=profit[i-1];
				}
			}
			ans+=temp;
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
	