#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
map <int,int>m;

void sieve(int n){
	bool primeArray[n+1];
	int i=0,temp=0;
	for(i=0;i<=n;i++){
		primeArray[i]=true;
	}

	for(temp=2;temp*temp<=n;temp++){
		if(primeArray[temp]==true){
			for(i=temp*temp;i<=n;i+=temp){
				primeArray[i]=false;
			}
		}
	}
	for(i=2;i<=n;i++){
		if(primeArray[i]==true)
			m[i]=1;
	}
}
int main() {
	// your code goes here
	
	int i,j,n;
	cin >> n;
	int array[n+1];
	int currentPrime = 0;
	sieve(n);
	for(i=2;i<=n;i++){
		if(m.find(i)!=m.end()){
			currentPrime++;
			for(j=i;j<=n;j+=i){
				array[j]=currentPrime;
			}
		}
		/*else{

		}*/
	}

	for(i=2;i<=n;i++){
		cout << array[i] << " ";
	}
	return 0;
}