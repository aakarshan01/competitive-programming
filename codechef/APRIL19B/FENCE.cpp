#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define SIZE 2002
int mod = 1000000007;

int main() {
	// your code goes here
	int t, n, k, i,r,c,m;
	long ans = 0;

	cin >> t;
	
	while(t>0){
		map <pair<int,int>, int> plants;
		ans = 0;
		
		cin >> n >> m >> k;
		int array[k][2];
		
		for(i=0;i<k;i++){
			cin >> r >> c;
			plants[make_pair(r,c)] = 1;
			array[i][0] = r;
			array[i][1] = c;
		}
		
		for(i=0;i<k;i++){
			r = array[i][0];
			c = array[i][1];
			if(plants.find(make_pair(r-1,c)) == plants.end())
				ans++;
			if(plants.find(make_pair(r+1,c)) == plants.end())
				ans++;
			if(plants.find(make_pair(r,c-1)) == plants.end())
				ans++;
			if(plants.find(make_pair(r,c+1)) == plants.end())
				ans++;
		}

		cout << ans << endl;

		t--;
	}

	return 0;
}
	