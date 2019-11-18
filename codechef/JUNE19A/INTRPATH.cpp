#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#include <map>

using namespace std;
int visited[300005];
int children[300005];
int parentArr[300005];
long long int tempAns[300005];

/*void printArray(int array[], int n){
	for(int i = 0; i<n;i++)
		cout << array[i] << " ";
	cout << endl;
}*/
int calcChildren(int currentVertex, int parent, vector<int> graph[]){
	int i = 0;
	int sum = 1;
	visited[currentVertex] = 1;
	parentArr[currentVertex] = parent;
	for(i=0;i<graph[currentVertex].size();i++){
		if(visited[graph[currentVertex][i]]==0){
			//visited[graph[currentVertex][i]] = 1;
			sum+=calcChildren(graph[currentVertex][i], currentVertex, graph);
		}
	}
	int tempsum = sum-1;
	int current = 1;
	long long int temp = 0;
	for(i=0;i<graph[currentVertex].size();i++){
		if(graph[currentVertex][i]!=parentArr[currentVertex]){
			current = children[graph[currentVertex][i]];
			temp += current * (tempsum - current);
			tempsum -= current;
		}
	}
	tempAns[currentVertex] = temp;
	children[currentVertex] = sum;
	return sum;
}
int main() {
	int t, n, q, u, v;
	register int i,j,k;
	scanf("%d", &t);
	while(t!=0){
		scanf("%d", &n);
		scanf("%d", &q);
		vector<int>graph[n];
		for(i=0;i<n-1;i++){
			scanf("%d", &u);
			scanf("%d", &v);
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
			visited[i] = 0;
		}
		visited[i] = 0;
		calcChildren(0,-1,graph);
		//cout << endl << "children array = " ; printArray(children, n);
		//cout << "parent array = " ; printArray(parentArr, n);
		//cout << "tempAns array = " ; printArray(tempAns, n);
		map<pair<int,int>, long long int> prevAns;
		for(j=0;j<q;j++){
			long long int ans = 0;
			scanf("%d", &u);
			scanf("%d", &v);
			u--;v--;

			if(prevAns.find(make_pair(u,v)) != prevAns.end()){
				printf("%lld \n", prevAns[make_pair(u,v)]);
				continue;
			}
			vector<int> path;
			vector<int> tempVec;
			//cout << "yo0" << endl;
			map<int,int> m;
			int current = v;
			while(current!=-1){
				m[current] = 1;
				current = parentArr[current];
			}
			current = u;
			//cout << "yo1" << endl;
			while(m.find(current) == m.end()){
				path.push_back(current);
				current = parentArr[current];
			}
			int lca = current;
			current = v;
			//cout << "lca =" << lca << endl;
			
			while(current!=lca){
				tempVec.push_back(current);
				current = parentArr[current];
			}
			tempVec.push_back(current);
			reverse(tempVec.begin(), tempVec.end());
			path.insert(path.end(), tempVec.begin(), tempVec.end());

			/*cout << "path = ";
			for(i=0;i<path.size();i++)
				cout << path[i] << " ";
			cout << endl;*/

			int prev = -1, next = -1;
			for(k=0;k<path.size();k++){
				if(k==path.size()-1)
					next = -1;
				else
					next = path[k+1];
				int currentVertex = path[k];
				long long int temp = 1;
				
				if(parentArr[currentVertex] == -1){
					long long int x1=0,x2=0,x=0;
					if(prev!=-1)
						x1+=children[prev];
					if(next!=-1)
						x2+=children[next];
					x = x1 + x2;
					//cout << " k1 = " << k << " prev = " << prev << " next = " << next << " x = " << x << " s = " << tempAns[currentVertex] + children[currentVertex] << endl;
					temp += tempAns[currentVertex] - x*(children[currentVertex]-1-x) - (x1*x2) + children[currentVertex] - 1 - x;
				}
				else if(parentArr[currentVertex] != next && parentArr[currentVertex] != prev){
					long long int x = 0,x1=0,x2=0;
					if(prev!=-1)
						x1+=children[prev];
					if(next!=-1)
						x2+=children[next];
					x=x1+x2;
					long long int childs =  tempAns[currentVertex] - x*(children[currentVertex]-1-x) - (x1*x2);
					//cout << " k2 = " << k << " x = " << x << " childs = " << childs << " yo = " << children[currentVertex] << endl;
					temp += (n-children[currentVertex]+1) * (children[currentVertex]-x) + childs - 1;
				}
				else if(parentArr[currentVertex] == prev){
					long long int x = 0;
					if(next!=-1)
						x+=children[next];
					//cout << " k3 = " << k << " x = " << x << endl;
					temp += children[currentVertex] - 1 + tempAns[currentVertex] - (children[currentVertex] - x)*(x);
				}
				else if(parentArr[currentVertex] == next){
					long long int x = 0;
					if(prev!=-1)
						x += children[prev];
					//cout << " k4 = " << k << " x = " << x << endl;
					temp += children[currentVertex] - 1 + tempAns[currentVertex] - (children[currentVertex] - x)*(x);
				}
				else{
					//cout << " yo " << endl;
				}
				//cout << " currentVertex = " << currentVertex << " temp = " << temp << endl;
				prev = currentVertex;
				ans+=temp;
			}
			prevAns[make_pair(u,v)]=ans;
			prevAns[make_pair(v,u)]=ans;
			printf("%lld \n",ans);
			//cout << ans << endl;
		}
		t--;
	}
}
	