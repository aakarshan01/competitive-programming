#include <iostream>
#include <map>
#include <vector>

using namespace std;

int gcd(int a,int b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int n,k, goLeft = 0,i,ans = 1;
	cin >> n;
	

	int array[n];

	cin >> array[0];
	int initialGCD=array[0];
	for(i=1;i<n;i++){
		cin >> array[i];
		//cout << initialGCD << endl;
		initialGCD = gcd(initialGCD, array[i]);
	}
	//cout << initialGCD << endl;
	for(i=0;i<n;i++){
		array[i] = array[i] / initialGCD;
	}
	int currentAns = 1;
	int firstPrimeIndex = -1,firstPrime = -1, secondPrimeIndex = -1, secondPrime = -1;
	int count  = 0;
	int temp = array[0];

	for(i=1;i<n;i++){
		temp = gcd(temp, array[i]);
		if(temp == 1){
			firstPrimeIndex = i;
			break;
		}
	}
	for(i=0;i<n;i++){
		if(i==firstPrimeIndex)
			continue;
		if(gcd(array[i], array[firstPrimeIndex]) == 1){
			secondPrimeIndex = i;
			break;
		}
	}

	if(n == 1){
		currentAns = 1;
	}
	else{
		int withoutFirstGCD = array[secondPrimeIndex];
		int withoutSecondGCD = array[firstPrimeIndex];
	    for(i=0;i<n;i++){
	    	if(i==firstPrimeIndex)
	    		continue;
			withoutFirstGCD = gcd(withoutFirstGCD, array[i]);
		}
		for(i=0;i<n;i++){
	    	if(i==secondPrimeIndex)
	    		continue;
			withoutSecondGCD = gcd(withoutSecondGCD, array[i]);
		}
		if(withoutFirstGCD > withoutSecondGCD)
			currentAns = withoutFirstGCD;
		else
			currentAns = withoutSecondGCD;
	}
	//cout << " initialGCD = " << initialGCD << " currentAns = " << currentAns << endl;
	cout << initialGCD * currentAns << endl;
	return 0;
}