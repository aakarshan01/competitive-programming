#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool isFavourite(long long int n,long long int factor){
	long long int m = factor-1;
	if(m==0)
		return false;
	if((n/m)*(m+1) == n)
		return true;
	else
		return false;
}

int main() {
	// your code goes here
	long long int n, i,ans;
	cin >>n;
	long long int sum = 0;
	for(i=1;i*i<=n;i++){

		if(n%i==0){
			if(n/i==i){
				// i is a factor
				if(isFavourite(n,i)){
					sum+=i-1;
				}
			}
			else{
				// i and n/i are factors
				if(isFavourite(n,i)){
					sum+=i-1;
				}
				if(isFavourite(n,n/i)){
					sum+=n/i - 1;
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}