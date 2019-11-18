#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

long long int costs[10005];
long long int reverseCosts[10005];
vector<int> graph[10005];
int parent[10005];
long long int toll[10005];
int root;
long long int budget, ans=0;
int visited[10005];

void printArray(long long int array[], int n){
	int i;
	for(i=0;i<n;i++)
		cout << array[i] << " " ;
	cout << endl;
}

void updateCosts(int vertexNo, long long int discount){
	int i;
	costs[vertexNo] = costs[vertexNo] - discount;
	
	for(i=0;i<graph[vertexNo].size();i++){
		if(graph[vertexNo][i] != parent[vertexNo]){
			updateCosts(graph[vertexNo][i], discount);
		}
	}
}

long long int dfs(int vertexNo){
	int i;
	//costs[vertexNo] = toll[vertexNo] + parentCost;
	visited[vertexNo] = 1;
	long long int tempSum = toll[vertexNo];
	long long int tempMax = 0;

	for(i=0;i<graph[vertexNo].size();i++){
		if(visited[graph[vertexNo][i]] == 0){
			//parent[graph[vertexNo][i]] = vertexNo;
			tempMax = max(tempMax, dfs(graph[vertexNo][i]));
		}
	}
	reverseCosts[vertexNo] = tempSum + tempMax;
	return reverseCosts[vertexNo];
}

void calculate(int vertexNo){

	int i;
	visited[vertexNo] = 1;
	//ancestors.push_back(vertexNo);

	//costs[vertexNo] = costs[vertexNo] - parentDiscount;
	if(reverseCosts[vertexNo] > budget){
		long long int discount = min(toll[vertexNo], reverseCosts[vertexNo] - budget);
		//cout << "vertex = " << vertexNo+1 << " discount = " << discount << endl;
		ans = ans + 2*discount;
	}
	for(i=0;i<graph[vertexNo].size();i++){
		if(visited[graph[vertexNo][i]] == 0){
			calculate(graph[vertexNo][i]);
		}
	}
	/*
	long long int discount;
	if(costs[vertexNo] > budget){
		for(i=0;i<ancestors.size();i++){
			if(costs[ancestors[i]]>0){
				discount = min(costs[ancestors[i]], costs[vertexNo] - budget);
				//cout << "vertex = " << ancestors[i]+1 << " discount = " << discount << endl;
				updateCosts(ancestors[i], discount);
				//printArray(costs, 8);
				ans = ans + 2*discount;
				if(costs[vertexNo] <= budget){
					break;
				}
			}
		}
	}*/
}

int main() {
	// your code goes here
	int t,n,x,j,u,v;
	register int i;
	long long int k;
	cin >> t ;
	
	while(t!=0){
		//cin  >> n >> x >> k;
		scanf("%d", &n);
		scanf("%d", &x);
		scanf("%lld", &k);
		ans = 0;
		for(i=0;i<n;i++){
			scanf("%lld", &toll[i]);
			visited[i] = 0;
			graph[i].clear();
		}
		for(i=0;i<n-1;i++){
			scanf("%d", &u);
			scanf("%d", &v);
			//cin >> u >> v;
			u--;v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		root = x-1;
		budget = k;
		//parent[root] = -1;
		dfs(x-1);
		//printArray(reverseCosts,n);

		for(i=0;i<n;i++)
			visited[i] = 0;
		vector<int> ancestors;
		calculate(x-1);
		cout << ans << endl;
		t--;
	}
	return 0;
}
	