#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) 
{ 
    return (a.first > b.first); 
} 

int main() {
	// your code goes here
	int n,m;

	int a,b,c;
	register int i;
	long long int sum=0;

	cin >> n >> m;
	priority_queue <int, vector<int>, greater<int>> pq;
	for(i=0;i<n;i++){
		//cin >> a;
		scanf("%d", &a);
		pq.push(a);
		sum+=a;
	}

	vector<pair<int,int>> v;
	for(i=0;i<m;i++){
		scanf("%d",&b);
		scanf("%d",&c);
		v.push_back(make_pair(c,b));
	}
	sort(v.begin(), v.end(), comparator);
	for(i=0;i<m;i++){
		//scanf("%d",&b);
		//scanf("%d",&c);
		//cin >> b >> c;
		b = v[i].second;
		c = v[i].first;
		//cout << b << " " <<  c << endl;
		while(b!=0){
			int temp = pq.top();
			if(temp >= c)
				break;
			pq.pop();
			pq.push(c);
			sum = sum + c - temp;
			b--;
		}
	}
	cout << sum << endl;
	return 0;
}