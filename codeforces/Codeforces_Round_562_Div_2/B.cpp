#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	int i,j,n,m,a,b,x,y1,y2=-1,y=-1;

	cin >> n >> m;

	vector<pair<int, int>> valuesArr(m);
	for(i=0;i<m;i++){
		cin >> a >> b;
		if(b<a)
			swap(a,b);
		valuesArr[i].first = a;
		valuesArr[i].second = b;
		//cout << a << b << endl;
	}
	sort(valuesArr.begin(), valuesArr.end());

	int ans = -1;
	if(m<=2){
		ans = 1;
	}
	else{
		int temp1=1;
		for(i=0;i<m-1;i++){
			//cout << " a = " << valuesArr[i].first << " b = " << valuesArr[i].second << endl;
			if(valuesArr[i+1].first == valuesArr[i].first && valuesArr[i+1].second != valuesArr[i].second)
				temp1 = -1;
			if(valuesArr[i+1].first != valuesArr[i].first)
				break;
		}
		int temp = i;
		if(temp1==1)
			temp = 0;
		//cout << " temp = " << temp << endl;
		if(temp==0){
			ans = 1;
			x = valuesArr[temp].second;
			for(j=temp+1;j<m;j++){
				if(valuesArr[j].first == x || valuesArr[j].second == x){
					continue;
				}
				else if (y2==-1){
					y1 = valuesArr[j].first;
					y2 = valuesArr[j].second;
				}
				else if (valuesArr[j].first == y1 && valuesArr[j].second == y2){
					continue;
				}
				else if(y==-1){
					if(valuesArr[j].first == y1 || valuesArr[j].second == y1)
						y = y1;
					else if(valuesArr[j].first == y2 || valuesArr[j].second == y2)
						y=y2;
					else{
						ans = -1;
						break;
					}
				}
				else if(valuesArr[j].first == y || valuesArr[j].second == y){
					continue;
				}
				else{
					ans = -1;
					break;
				}
			}
		}
		else{
			ans = 1;
			x = valuesArr[temp].first;
			for(j=temp+1;j<m;j++){
				//cout << valuesArr[j].first << " " << valuesArr[j].second << " y = " << y << endl;
				if(j==temp+1){
					y1=valuesArr[j].first;
					y2=valuesArr[j].second;
				}
				else if(y==-1){
					if(valuesArr[j].first == y1 || valuesArr[j].second == y1)
						y = y1;
					else if(valuesArr[j].first == y2 || valuesArr[j].second == y2)
						y=y2;
					else{
						ans = -1;
						break;
					}
				}
				else if(valuesArr[j].first == y || valuesArr[j].second == y){
					continue;
				}
				else{
					ans = -1;
					break;
				}
			}
		}
		if(ans == -1){
			y1 = valuesArr[0].first; 
			for(i=0;i<m-1;i++){
				if(valuesArr[i+1].first != valuesArr[i].first){
					break;
				}
			}
			int temp = i;
			x = valuesArr[0].second;
			y = valuesArr[0].second;
			for(i=0;i<=temp;i++){
				if(valuesArr[i].second != x){
					y = valuesArr[i].second;
					temp = i;
					break;
				}
			}
			ans = 1;
			for(i=0;i<m;i++){
				if(valuesArr[i].first == x || valuesArr[i].second == x || valuesArr[i].first == y || valuesArr[i].second == y)
					continue;
				else{
					ans = -1;
					break;
				}
			}
		}
	}

	//cout << " x = " << x << " y = " << y << endl;
	if(ans==1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}