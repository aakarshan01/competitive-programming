#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//map <vector<int>, int> m;

int main() {
	// your code goes here
	int l,j,minAns=100000000,r,x,ans=0;
	
	int n,h,m;
	cin >> n >> m;
	int array[n];
	int i = 0;
	x = m;

	for(i=0;i<n;i++){
		array[i]=1;
	}
	int temp = 1;
	i=0;
	while(m!=0){
		if(temp==1&&array[i]==1){
			temp = 0;
			array[i]=0;
			m--;
		}
		else if(temp==0&&array[i]==1){
			temp=1;				
		}
		i=(i+1)%n;
	}
	/*for(i=0;i<n;i++){
		cout << array[i] << " ";
	}*/
	temp=0;
	for(i=0;i<n;i++){
		if(array[i]==1&&temp==0){
			ans++;
			temp=1;
			continue;
		}
		else if(array[i]==0){
			temp=0;
		}
	}
	if(array[0]==1 && array[n-1] == 1)
		ans--;

	if(x==0)
		ans=1;
	cout << ans << endl;

	return 0;
}
