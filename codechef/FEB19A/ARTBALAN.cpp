#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t, n, m,avg, k,q, i = 0, a, b, u,j, v, x,ctr;
	string s;
	cin >> t ;
	
	while(t!=0){
		cin >> s;
		int ans = 0;

		int l = s.size();
		vector<int> frequencyTable(26);

		for(i=0;i<26;i++){
			frequencyTable[i] = 0;
		}
		for(i=0;i<s.size();i++){
			frequencyTable[s[i] - 'A']++;
		}
		sort(frequencyTable.begin(), frequencyTable.end(), greater<int>());

		for(i=1;i<=26;i++){
			int temp = 0, inside = 0, positives = 0, negatives = 0;
			if(i > l)
				break;

			if(l % i == 0){
				inside = 1;
				avg = l / i;
				//cout << " number = " << i << " avg = " << avg << endl;
				for(j = 0; j < i; j++){
					//temp += abs(avg - frequencyTable[j]);
					if(frequencyTable[j] > avg)
						positives += frequencyTable[j] - avg;
					else if (frequencyTable[j] < avg)
						negatives += avg - frequencyTable[j];
				}
				while(j < 26 && frequencyTable[j] != 0){
					positives += frequencyTable[j];
					j++;
				}

				//cout << " positives = " << positives << " negatives = " << negatives << endl;
				temp = (positives + negatives) / 2;
			}
			if(i == 1)
				ans = temp;
			else if(inside == 1 && temp < ans)
				ans = temp;
			//cout << "ans = " << ans <<" ";
		}

		cout << ans << endl;
		t--;
	}
	return 0;
}
	