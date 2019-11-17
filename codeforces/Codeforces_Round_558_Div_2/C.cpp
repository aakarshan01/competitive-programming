#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	// your code goes here
	int i,n,j,k, goLeft = 0,x,y,x1,y1,x2,y2;
	cin >> n;

	long long int ans = 0;
	double t,c;
	map<pair<double, double>, int> m;
	map<double, int> slope;

	int array[n][2];
	for(i=0;i<n;i++){
		cin >> x >> y;
		array[i][0] = x;
		array[i][1] = y;
	}

	for(i=0;i<n;i++){
		x1 = array[i][0];
		y1 = array[i][1];

		for(j=i-1;j>=0;j--){
			x2 = array[j][0];
			y2 = array[j][1];

			if(x1==x2){
				t = INFINITY;
				c = x1;
			}
			else{
				t = (y2-y1) / (1.0*(x2-x1));
				c = y2 - t*x2;
			}
			
			if(m.find(make_pair(t,c)) == m.end()){
				if(slope.find(t) == slope.end())
				{
					slope[t]=1;
				}
				else
				{
					slope[t]++;
				}
			}
			m[make_pair(t,c)] = 1; 
		}
	}

	long long int lines = m.size();
	int distinctLines = slope.size();
	int parallel = lines-distinctLines;

	
	ans = (lines*(lines-1))/2;
	//cout << " lines = " << lines << endl;
	for(auto current = slope.begin(); current!=slope.end();current++){
		long long int temp = current->second;

		//cout << " temp = " << temp << endl;	
		ans = ans - (temp*(temp-1))/2;
	}
	cout << ans << endl;
	return 0;
}