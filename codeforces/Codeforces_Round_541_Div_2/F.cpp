#include <iostream>
#include <map>
#include <vector>

using namespace std;

int par[150005];
int input[150005][2];
vector<int> graph[150005];

int find(int i){
	if(par[i] == i)
		return i;
	return find(par[i]);
}

int main() {
	// your code goes here
	int i,j,n,m,a,b;
	cin >> n;

	for(i=0;i<n;i++){
		par[i] = i;
		graph[i].push_back(i);
	}

	for(i=0;i<n-1;i++){
		cin >> input[i][0] >> input[i][1];
		input[i][0]--;
		input[i][1]--;
	}

	for(i=0;i<n-1;i++){
		int parentA = find(input[i][0]);
		int parentB = find(input[i][1]);
		if(graph[parentB].size() > graph[parentA].size())
			swap(parentA, parentB);

		for(int i=0;i<graph[parentB].size();i++){
			graph[parentA].push_back(graph[parentB][i]);
		}
		par[parentB] = parentA;
	}
	int ans = find(par[0]);
	for(i=0;i<n;i++){
		cout << graph[ans][i] + 1 << " ";
	}
	
	return 0;
}
