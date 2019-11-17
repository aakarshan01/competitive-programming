#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int i,n,k;
	cin >> n;
	
	int last1=0, last0 = 0;
	for(i=0;i<n;i++){
		string s;
		cin >> s;
		int frequency[26];
		for(k=0;k<26;k++){
			frequency[k] = 0;
		}
		for(k=0;k<s.length();k++){
			frequency[s[k]-'a']++;
		}
		int ans = 1;

		for(k=0;k<26;k++){
			if(frequency[k]>1)
				ans = 0;
		}
		int first = -1, second = -1;
		for(k=0;k<26;k++){
			if(frequency[k]==1 && first == -1)
				first = k;
			else if(frequency[k] ==0 && first != -1 && second == -1)
				second = k;

			if(frequency[k] == 1 && second != -1){
				ans =0;
				break;
			}
		}

		//cout << first << second << endl;
		if(ans==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	
	return 0;
}
