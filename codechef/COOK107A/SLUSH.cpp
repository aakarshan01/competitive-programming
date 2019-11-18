#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t, n, m, k,q, i = 0, u,j, v, ctr;
	double a,b,x,y,z,sum,ans;
	cin >> t;

	while(t!=0){
		cin >> n >> m;
		int stock[m+1];
		int d[n+1];
		int f[n+1];
		int c[n+1];
		long long int cost = 0;
		int given[n+1];
		int needs[m+1];
		priority_queue<pair<int, int> > pq; 

		for(i=1;i<=m;i++)
		{
			cin >> stock[i];
			needs[i] = 0;
		}
		for(i=1;i<=n;i++)
		{
			cin >> d[i] >> f[i] >> c[i];
			needs[d[i]]++;
		}
		for(i=1;i<=m;i++)
		{
			if(stock[i]>needs[i])
			{
				pq.push(make_pair(stock[i]-needs[i], i));
			}
		}

		for(i=1;i<=n;i++)
		{
			int current = d[i];
			if(stock[current]>0)
			{
				stock[current]--;
				needs[current]--;
				cost+=f[i];
				given[i] = current;
			}
			else
			{
				pair<int, int> top = pq.top();
				int topIndex = top.second;
				stock[topIndex]--;
				pq.pop();
				if(stock[topIndex]>needs[topIndex])
					pq.push(make_pair(stock[topIndex]-needs[topIndex], topIndex));
				cost+=c[i];
				given[i] = topIndex;
			}
			//cout << cost << endl;
		}

		cout << cost << endl;
		for(i=1;i<=n;i++)
			cout << given[i] << " ";
		t--;
	}



	return 0;
}
	