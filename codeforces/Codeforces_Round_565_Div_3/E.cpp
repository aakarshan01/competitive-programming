#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int colorArray[200005]; 

bool colorGraph(vector<int> graph[], int src, int n, int m) 
{ 
	int i,j;
	int visited[n];

    for(i=0;i<n;i++){
    	colorArray[i] = -1;
    	visited[i] = 0;
    }
    queue<int> q;
    colorArray[src] = 0;
    q.push(src);

    while(!q.empty()){
    	int currentVertex = q.front();
    	int currentColor = colorArray[currentVertex];
    	q.pop();
    	for(i=0;i<graph[currentVertex].size();i++){
    		if(colorArray[graph[currentVertex][i]]==-1){
    			//cout << i << " graph[currentVertex][i] = " << graph[currentVertex][i] << endl; 
    		
    			colorArray[graph[currentVertex][i]] = 1 - currentColor;
    			q.push(graph[currentVertex][i]);
    		}
    	}
    }
} 

int main() {
	// your code goes here
	int t, n, i, u, v, m;
	cin >> t;
	while(t!=0){
		cin >> n >> m;
		vector<int> graph[n];
		
		for(i=0;i<m;i++){
			cin >> u >> v;
			u--;
			v--;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int zero=0,one=0;
		colorGraph(graph,0,n,m);
		for(i=0;i<n;i++){
			//cout << colorArray[i] << " ";
			if(colorArray[i] == 0){
				zero++;
			}
			else if (colorArray[i] == 1){
				one++;
			}
		}
		//cout << endl << zero << " " << one << endl;
		if(zero<one){
			cout << zero << endl;
			for(i=0;i<n;i++){
				if(colorArray[i] == 0){
					cout << i+1 << " ";
				}
			}
			cout << endl;
		}
		else{
			cout << one << endl;
			for(i=0;i<n;i++){
				if(colorArray[i] == 1){
					cout << i+1 << " ";
				}
			}
			cout << endl;
		}
		t--;
	}
	

	return 0;
}