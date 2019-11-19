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
	int n,a=0,b=0,i,j,same=1,ans=0,atleastOne= 0;

	cin >> n;
	string s;
	for(i=0;i<n;i++){
		cin >> s;
		
		for(j=0;j<s.length()-1;j++){
			if(s[j]=='A'&&s[j+1]=='B'){
				ans++;
			}
		}

		int in = 0;
		if(s[s.length()-1]=='A'){
			a++;
			in++;
		}
		if(s[0]=='B'){
			b++;
			in++;
		}
		if(in==1)
			same=0;
		if(in>0)
			atleastOne = 1;
	}
	//cout << "a = "
	if(a==b && atleastOne == 1 && same == 1){
		ans = ans + a - 1;
	}
	else{
		ans = ans + min(a,b);
	}
	cout << ans << endl;
	return 0;
}