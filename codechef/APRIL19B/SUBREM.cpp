#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int n;
int input[100005];
//long long int sum[100005];
long long int visited[100005];
long long int ans = 0,k=0,x;

long long int algorithm(vector<int> graph[], int vertexNo){
	long long int tempSum = 0,i;
	//cout << vertexNo << endl;
	visited[vertexNo] = 1;
	for(i=0;i<graph[vertexNo].size();i++){
		if(visited[graph[vertexNo][i]] == 0)
			tempSum += algorithm(graph, graph[vertexNo][i]);
	}
	tempSum += input[vertexNo];

	if(-x < tempSum)
		return tempSum;
	else
		return -x;
}

/*
long long int preprocess(vector<int> graph[], int vertexNo){
	long long int tempSum = 0,i;
	//cout << vertexNo << endl;
	for(i=0;i<graph[vertexNo].size();i++){
		tempSum += preprocess(graph, graph[vertexNo][i]);
	}
	tempSum += input[vertexNo];
	sum[vertexNo] = tempSum;
	return tempSum;
}*/

int main() {
	// your code goes here
	int t, k, i, u, v, j, size, root, xIndex, repeat,l ,r, f, cf;

	cin>>t;

	while(t!=0){
		cin >> n >> x;	// x is penalty
		ans=0;
		k=0;
		vector<int> graph[n];
		
		for(i=0;i<n;i++){
			scanf("%d", &input[i]);
			visited[i] = 0;
		}
		for(i=0;i<n-1;i++){
			cin >> u >> v;
			graph[u-1].push_back(v-1);
			graph[v-1].push_back(u-1);
		}
		
		/*
		preprocess(graph, 0);

		for(i=0;i<n;i++){
			cout << sum[i] << " ";
		}
		cout << endl;*/

		ans = algorithm(graph, 0);

		
		cout << ans << endl;
		t--;
	}
	return 0;
}
	