#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> v1;
vector<pair<int, int>> v2;

int main() {
	// your code goes here
	int i,j,n,temp,r1,c1,r2,c2;
	int ans = -1;

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	r1--;c1--;r2--;c2--;
	int graph[n][n];
	int visited[n][n];

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			char temp;
			cin >> temp;
			graph[i][j] = temp - '0';
			visited[i][j] = 0;
		}
	}

	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	q1.push(make_pair(r1, c1));
	v1.push_back(make_pair(r1,c1));
	visited[r1][c1] = 1;
	while(!q1.empty()){
		pair<int, int> tempPair = q1.front();
		q1.pop();

		int x = tempPair.first;
		int y = tempPair.second;
		if(x - 1 >= 0 && graph[x-1][y] == 0 && visited[x-1][y] == 0){
			q1.push(make_pair(x-1, y));
			v1.push_back(make_pair(x-1, y));
			visited[x-1][y] = 1;
		}
		if(x + 1 < n && graph[x + 1][y] == 0 && visited[x+1][y] == 0){
			q1.push(make_pair(x+1,y));
			v1.push_back(make_pair(x+1,y));
			visited[x+1][y] = 1;
		}
		if(y - 1 >= 0 && graph[x][y-1] == 0 && visited[x][y-1] == 0){
			q1.push(make_pair(x, y-1));
			v1.push_back(make_pair(x, y-1));
			visited[x][y-1] = 1;
		}
		//cout << y + 1 << " " << graph[x][y+1]<<" " << visited[x][y+1]<<endl;
		if(y + 1 < n && graph[x][y+1] == 0 && visited[x][y+1] == 0){
			//cout << "yo" << endl;
			q1.push(make_pair(x,y+1));
			v1.push_back(make_pair(x,y+1));
			visited[x][y+1] = 1;
		}
	}

	if(visited[r2][c2] == 1){
		cout << 0 << endl;
		return 0;
	}

	q2.push(make_pair(r2, c2));
	v2.push_back(make_pair(r2,c2));
	visited[r2][c2] = 1;
	while(!q2.empty()){
		pair<int, int> tempPair = q2.front();
		q2.pop();

		int x = tempPair.first;
		int y = tempPair.second;
		if(x - 1 >= 0 && graph[x-1][y] == 0 && visited[x-1][y] == 0){
			q2.push(make_pair(x-1, y));
			v2.push_back(make_pair(x-1, y));
			visited[x-1][y] = 1;
		}
		if(x + 1 < n && graph[x + 1][y] == 0 && visited[x+1][y] == 0){
			q2.push(make_pair(x+1,y));
			v2.push_back(make_pair(x+1,y));
			visited[x+1][y] = 1;
		}
		if(y - 1 >= 0 && graph[x][y-1] == 0 && visited[x][y-1] == 0){
			q2.push(make_pair(x, y-1));
			v2.push_back(make_pair(x, y-1));
			visited[x][y-1] = 1;
		}
		if(y + 1 < n && graph[x][y+1] == 0 && visited[x][y+1] == 0){
			q2.push(make_pair(x,y+1));
			v2.push_back(make_pair(x,y+1));
			visited[x][y+1] = 1;
		}
	}

	/*for(i=0;i<v1.size();i++){
		cout << v1[i].first << " " << v1[i].second << endl;
	}
	cout << " ---- v2 : ----" << endl;
	for(i=0;i<v2.size();i++){
		cout << v2[i].first << " " << v2[i].second << endl;
	}*/

	ans = (r2 - r1) * (r2 - r1) + (c2 - c1) * (c2 - c1);
	for(i=0;i<v1.size();i++){
		for(j=0;j<v2.size();j++){
			int distance = (v2[j].first - v1[i].first) * (v2[j].first - v1[i].first) + (v2[j].second - v1[i].second) * (v2[j].second - v1[i].second);
			ans = min(ans, distance);
		}
	}
	cout << ans << endl;

	return 0;
}
