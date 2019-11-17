#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i;
	cin >> n;

	int num[10];
	int ndigits = 0;
	int ncopy = n;
	while(n!=0){
		k=n%10;
		n=n/10;
		num[ndigits++] = k;
	}

	long long ans = 1;
	for(i=0; i<ndigits-1;i++){
		ans = ans * 9;
	}

	if(ndigits > 1){
		//ans = ans / 9;
		int temp = num[ndigits-1]*10+num[ndigits-2];
		
		int maxProduct = 1, ok=1;
		if(ndigits == 2)
			temp++;
		if(ndigits>2){
			for(i=ndigits-3;i>=0;i--){	
				if(num[i] != 9)
					ok = 0;
			}
		}
		if(ok==1)
			temp++;
		

		for(i=10;i<temp;i++){
			int temp1 = i%10 * (i/10);
			if(temp1>maxProduct)
				maxProduct = temp1;
		}

		//cout << maxProduct << " saas ans = " << ans << " temp = " << temp << endl;
		if(maxProduct > 9){
			ans = (ans * maxProduct) / 9;
		}
	}
	else{
		ans = ncopy;
	}


	cout << ans << endl;

	return 0;
}