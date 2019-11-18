#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int n;
long long int valueArray[100005];
long long int modArray[100005];
vector <pair<int, long long int> > ansArray;
long long int visited[100005];
long long int ans = 0,k=0,x;

long long int gcd(long long int a, long long int b){
	if(a==0)
		return b;
	return gcd(b%a,a);
}

void algorithm(vector<int> graph[], int vertexNo, long long int gcdTillNow){
	long long int tempSum = 0,i;
	
	visited[vertexNo] = 1;
	//sumTillNow += valueArray[vertexNo];
	gcdTillNow = gcd(gcdTillNow, valueArray[vertexNo]);

	//cout << "gcdTillNow = " << gcdTillNow << endl;
	
	for(i=0;i<graph[vertexNo].size();i++){
		if(visited[graph[vertexNo][i]] == 0)
			algorithm(graph, graph[vertexNo][i], gcdTillNow);
	}

	if(vertexNo !=0 && graph[vertexNo].size() == 1){ // this means this is leaf
		long long int A = gcdTillNow;
		long long int B = modArray[vertexNo];
		long long int gcdAB = gcd(A,B);
		long long lowestFormA = A / gcdAB;
		long long lowestFormB = B / gcdAB;
		//cout << " vertexNo = " << vertexNo << " A = " << A << " B = " << B << endl;
		ansArray.push_back(make_pair(vertexNo, (lowestFormB-1)*gcdAB));
	}
}
int main() {
	// your code goes here
	int t, k, i, u, v, j, size, root, xIndex, repeat,l ,r, f, cf;

	cin>>t;

	while(t!=0){
		cin >> n;	// x is penalty
		ans=0;
		k=0;
		vector<int> graph[n];
		ansArray.clear();
		for(i=0;i<n;i++){
			visited[i] = 0;
		}
		for(i=0;i<n-1;i++){
			scanf("%d", &u);
			scanf("%d", &v);
			graph[u-1].push_back(v-1);
			graph[v-1].push_back(u-1);
		}
		
		for(i=0;i<n;i++){
			scanf("%lld", &valueArray[i]);
			//cin >> valueArray[i];
		}
		for(i=0;i<n;i++){
			scanf("%lld", &modArray[i]);
			//cin >> modArray[i];
		}
		algorithm(graph, 0, valueArray[0]);

		sort(ansArray.begin(), ansArray.end());
		//cout << ansArray.size() << endl;
		for(i=0;i<ansArray.size();i++){
			cout << ansArray[i].second << " ";
		}	
		cout << endl;

		t--;
	}
	return 0;
}
	