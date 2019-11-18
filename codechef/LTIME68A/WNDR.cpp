#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int main() {
	// your code goes here
	int t, n, m, k,q, i = 0, a, b, u,j, v, ctr;
	int rowNo=0, colNo = 0;
	long ans = 0;
	cin >> t ;
	
	while(t!=0){
		ans = 0;
		cin >> n >> m >> k;
		vector < vector <int> > adjacencyList(n);
		
		while(m!=0){
			cin >> u >> v;
			adjacencyList[u-1].push_back(v-1);
			adjacencyList[v-1].push_back(u-1);
			m--;
		}
		
		cin >> q;
		vector < pair <int, int> > conditions(q);

		for(i=0;i<q;i++){
			cin >> a >> b;
			conditions[i] = make_pair(a-1, b);
		}
		sort(conditions.begin(), conditions.end(), comparator);
		vector <int> prev(n);
		vector <int> current(n); 
		for(i=0;i<n;i++){
			prev[i] = 0;
			current[i] = 0;
			adjacencyList[i].push_back(i);
		}
				int pastTime = -2, presentTime = -2, pastValue = -2, presentValue = -2 ;
		prev[0]=1;
		if(q == 0){
			ctr = -1;
		}
		else{
			pastTime = conditions[0].second;
			pastValue = conditions[0].first;
			ctr = 0;
		}


		for(i=0;i<conditions.size();i++){
			presentTime = conditions[i].second;
			presentValue = conditions[i].first;
			if(presentTime == pastTime && pastValue!=presentValue){
				prev[0] = 0;
				//cout << "Not Possible" << endl;
			}
		}
		
		if(ctr!=-1 && conditions[ctr].second == 0){
			if(conditions[ctr].first != 0){
				prev[0] = 0;
			}
		}
		
		if(prev[0] == 0){
			ans = 0;
		}
		else{
			for(i=0;i<k;i++){
				for(j=0;j<n;j++){
					current[j] = 0;
					if(ctr!=-1 && i==conditions[ctr].second - 1){
						if(j!=conditions[ctr].first){
							//cout << current[j] << " ";
							continue;
						}
					}
					for (auto it = adjacencyList[j].begin(); it != adjacencyList[j].end(); ++it) {
						int neighbour = *it;
						current[j] = (current[j] + prev[neighbour]) % mod; 
					}
					if(i==k-1){
						ans = (ans + current[j]) % mod;
					}
					//cout << current[j] << " ";
				}
				//cout << endl << " --- next ----" << endl;
				prev = current;
				if(ctr!=-1 && i==conditions[ctr].second - 1){
					ctr++;
				}
			}
		}
		cout << ans << endl;
		t--;
	}
	return 0;
}
	