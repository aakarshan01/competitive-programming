#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here

	int i,j,y,n,x,ans;
	cin >> n;
	int array[n];
	int freqTable[100005];

	for(i=0;i<n;i++){
		cin >> array[i];
	}
	for(i=0;i<100005;i++){
		freqTable[i] = 0;
	}

	map <int, int> m;
	int tempAns=0;
	for(i=0;i<n;i++){
		int prev = freqTable[array[i]];
		freqTable[array[i]]++;
		int next = freqTable[array[i]];

		if(prev>0){
			m[prev]--;
			if(m[prev]==0){
				m.erase(prev);
			}
		}
		if(m.find(next)==m.end()){
			m[next] = 1;
		}
		else{
			//cout << "found" <<endl;
			m[next]++;	
		}

		//cout << " prev = " << prev << " next = " << next << " m.size()= " << m.size() << endl;
		
		if(m.size()==1){
			//if(m.begin()->second == 1){
			auto it = m.begin();
			int q = it->second;
			int q1 = it->first;
			//cout << " q = " << q << " q1 = " << q1 << endl;
			if(q1==1 || q == 1){
				//cout << " ans = " << i+1 << endl;
				ans = i + 1;
			}
		}
		else if(m.size() == 2){
			auto it = m.begin();
			int q = it->second;
			int q1 = it->first;
			it++;
			int w = it->second;
			int w1 = it->first;
			
			//cout << " q = " << q << " w = " << w << " q1 = " << q1 << " w1 = " << w1 << endl;
			if((q==1 && q1 == 1) || (w==1 && w1 == 1)){
				ans = i + 1;
			}
			else if(w==1 && (w1-q1 == 1)){
				ans = i + 1;
			}
			else if(q==1 && (q1-w1 == 1)){
				ans = i + 1;
			}
		}
		//cout << ans << endl;
	}

	cout << ans << endl;


	return 0;
}
