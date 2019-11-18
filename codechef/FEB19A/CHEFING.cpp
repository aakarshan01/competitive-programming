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
	int t, n, m, k,q, i = 0, a, b, u,j, v, ctr;
	string s;
	cin >> t ;
	
	while(t!=0){
		cin >> n;
		int frequencyTable[26];
		int alreadyCounted[26];

		int ans = 0;
		for(i=0;i<26;i++){
			frequencyTable[i] = 0;
		}

		for(m=0;m<n;m++){
			cin >> s;

			for(i=0;i<26;i++){
				alreadyCounted[i] = 0;
			}

			for(i=0;i<s.size();i++){
				if(alreadyCounted[s[i] - 'a'] == 0) {
					frequencyTable[s[i] - 'a']++;
					alreadyCounted[s[i] - 'a'] = 1;
				}
			}
		}
		for(i=0;i<26;i++){
			if(frequencyTable[i] == n){
				ans++;
			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
	