#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,q,i,z,j,k;
	cin >> q;
	string s,t,p;
	while(q!=0)
	{
		cin >> s >> t >> p;
		int freqS[26];
		int freqT[26];
		int freqP[26];
		for(i=0;i<26;i++)
		{
			freqS[i]=0;
			freqT[i]=0;
			freqP[i]=0;
		}
		for(i=0;i<s.size();i++)
		{
			freqS[s[i]-'a']++;
		}
		for(i=0;i<t.size();i++)
		{
			freqT[t[i]-'a']++;
		}
		for(i=0;i<p.size();i++)
		{
			freqP[p[i]-'a']++;
		}
		int ans = 1;
		for(i=0;i<26;i++)
		{
			if(freqS[i]>freqT[i])
			{
				ans = 0;
				break;
			}
			if(freqT[i]==0)
				continue;
			//cout << freqS[i] << freqT[i] << freqP[i] << endl;
			if(freqS[i] + freqP[i] >= freqT[i])
				continue;
			else
			{
				ans = 0;
				break;
			}
		}
		if(ans==1)
		{
			int current = 0;
			for(i=0;i<t.size();i++)
			{
				if(current==s.size())
					break;
				while(i<t.size() && t[i]!=s[current])
				{
					i++;
				}
				if(i<t.size())
				{
					current++;
				}
			}
			if(current<s.size())
			{
				ans = 0;
			}
		}
		if(ans==1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		q--;
	}

	return 0;
}
