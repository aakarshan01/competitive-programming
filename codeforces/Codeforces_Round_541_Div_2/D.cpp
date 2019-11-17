#include <iostream>
#include <map>
#include <vector>

using namespace std;

int par[2005];
int visited[2005];
int currentStack[2005];
int ans[2005];

vector<int> equalSets[2005];
vector<int> graph1[2005];

void printArray(int arr[], int n){
	for(int i = 0; i < n;i++){
		cout << arr[i] << " " ;
	}
	cout << endl;
}

int find(int i){
	if(par[i] == i)
		return i;
	return find(par[i]);
}
int ctr =0 ;
int dfs(int current){

	int tempCurrent = current;
	current = find(current);

	ctr++;
	//for(int x=0;x<ctr;x++){cout << "    ";}
	//cout << "tempCurrent = " << tempCurrent << endl ;

	if(visited[tempCurrent] == 0){
		visited[tempCurrent] = 1;
		currentStack[current] = 1;

		int i=0,j=0,val = 0;
		int temp = 0, maxSib = 0;

		//cout << " size = " << equalSets[current].size() << endl;
		for(j=0;j<equalSets[current].size();j++){
			int sibling = equalSets[current][j];
			val = 0;
			//cout << " child size = " << graph1[sibling].size() << " sibling = " << sibling << endl;
			for(i=0;i<graph1[sibling].size();i++){
				int child = graph1[sibling][i];
				if(visited[child] == 0){
					temp = dfs(child);
				}
				if(temp == -1)
					return -1;
				else if(currentStack[find(child)] == 1)
					return -1;
				temp = dfs(child);
				val = max(val, temp);
			}
			if(i==0){
				//currentStack[current] = 0;
				ans[sibling] = 1;
				//cout << "sibling = " << sibling << "ans[sibling] = " << ans[sibling] <<endl;
				//cout << "returned 1" << endl;
				//return 1;
			}
			else{
				currentStack[current] = 0;
				ans[sibling] = val + 1;
				//cout << "sibling = " << sibling << "ans[sibling] = " << ans[sibling] <<endl;
				//return val + 1;
			}
			maxSib = max(ans[sibling], maxSib);
			visited[sibling] = 1;
		}
		//for(j=0;j<equalSets[current].size();j++)
		ans[current] = maxSib;
		//ans[tempCurrent] = maxSib;
	}
	currentStack[current] = 0;
	ctr--;
	return ans[current];
}

int main() {
	// your code goes here
	int i,j,n,m,k;
	cin >> n >> m;

	for(i=0;i<n+m;i++){
		par[i] = i;
		equalSets[i].push_back(i);
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			char symbol;
			cin >> symbol;

			if(symbol == '>'){
				graph1[i].push_back(n+j);
			}
			else if(symbol == '<'){
				graph1[n+j].push_back(i);
			}
			else{
				int x = find(i);
				int y = find(n+j);

				if(x==y)
					continue;
				if(equalSets[y].size() > equalSets[x].size()){
					swap(x,y);
				}
				for(k=0;k<equalSets[y].size();k++){
					equalSets[x].push_back(equalSets[y][k]);
				}
				par[y] = x;
				//printArray(par, n+m);
			}
		}
	}
	//printArray(par, n+m);

	for(i=0;i<n+m;i++){
		int tempAns = dfs(i);
		if(tempAns == -1){
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	
	/*for(i=0;i<n+m;i++){
		cout << par[i] << " ";
	}
	cout << endl;*/

	for(i=0;i<n+m;i++){
		cout << ans[find(i)] << " ";
		if(i==n-1)
			cout << endl;
	}
	
	return 0;
}
