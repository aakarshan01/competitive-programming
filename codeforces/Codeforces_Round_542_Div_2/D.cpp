#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int par[1000];
int find(int i){
	if(par[i] == i)
		return i;
	return par[i];
}

int main() {
	// your code goes here
	int i,j,a,b,n,m,ans;
	cin >> n >> m;
	
	vector<int> matrix[n];

	for(i=0;i<m;i++){
		cin >> a >> b;
		a--;
		b--;
		int temp = (b + n - a) % n;
		matrix[a].push_back(temp);
	}
	int maxSize = matrix[0].size();
	for(i=0;i<n;i++){
		sort(matrix[i].begin(), matrix[i].end(), greater<int>());
		int temp = matrix[i].size();
		maxSize = max(maxSize, temp);
	}

	int lastTimes[n];
	int secondLastTimes[n];
	for(i=0;i<n;i++){
		if (maxSize == matrix[i].size()){
			lastTimes[i] = matrix[i][maxSize-1];
			secondLastTimes[i] = -1;
		}
		else if(matrix[i].size() > 0 && matrix[i].size() == maxSize - 1){
			secondLastTimes[i] = matrix[i][maxSize-2];
			lastTimes[i] = -1;
		}
		else{
			lastTimes[i] = -1;
			secondLastTimes[i] = -1;
		}
		//cout << lastTimes[i] << " ";		
		//cout << secondLastTimes[i] << " ";
	}
	//cout << endl;
	
	
	for(i=0;i<n;i++){
		ans = 0;
		int index = i, tempMax = 0;
		for(j=i-1;j>=-1;j--){
			if(j==-1)
				j=n-1;
			if(lastTimes[j]!=-1){
				//index = j;
				int temp = (j + n - i) % n + lastTimes[j];
				
				if(temp > tempMax){
					tempMax = temp;
					index = j;
				}
				//tempMax = max(tempMax, temp);
			}
			else if(j!=i && secondLastTimes[j]!=-1){
				//index = j;
				int temp = secondLastTimes[j] - (i + n - j) % n;
				
				if(temp > tempMax){
					tempMax = temp;
					index = j;
				}
				//tempMax = max(tempMax, temp);
			}
			if(j==i)
			    break;
		}
		//cout << index << " " ;
		//int temp = (index + n - i) % n;
		ans = ans + (maxSize - 1) * n + tempMax;
		//cout << temp << endl; 
		cout << ans << " " ;
	}

	return 0;
}