#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#include <map>
using namespace std;

map<string, long long int> m;

bool isPalindrome(string s){
	int i;
	for(i=0;i<s.length()/2;i++){
		if(s[i] != s[s.size() - 1])
			return false;
	}
	return true;
}

long long int algorithm(string s, int cut){
	long long int temp = 0,i,j,l;
	
	cout << "string = " << s << " cut = " << cut << endl;
	if(s.length() == 1)
		return 0;

	if(m.find(s) != m.end())
		return m[s];

	if(isPalindrome(s)){
		temp = s.length() - 1;
	}

	string s1;
	if(cut==0){
		for(l=1;l<s.length()-1;l++){
			for(i=0;i<s.length()-l+1; i++){
				j=i+l;
				s1 = s;
				s1.erase(s1.begin() + i, s1.begin() + j);
				

				//cout << " i = " << i << " j = " << j << " s1 = " << s1 << endl;
				if(i==0 || i==s.length()-l+1)
					temp += algorithm(s1, 0);
				else
					temp += algorithm(s1, 1);
			}
		}
	}	

	cout << " string = " << s << " ans = " << temp << " cut = " << cut << endl;
	m[s] = temp;
	return temp;
}
int main() {
	// your code goes here
	int t, k, i, u, v, j, size, root, xIndex, repeat,l ,r, f, cf;
	string s;
	cin>>s;

	long long int ans = algorithm(s,0);
	cout << ans << endl;
	return 0;
}
	