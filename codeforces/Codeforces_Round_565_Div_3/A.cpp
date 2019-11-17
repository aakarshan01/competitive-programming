#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	int cnt=0,i,j,n,m,a,b,x,y1,q,y2=-1,y=-1;

	long long int num = 0;
	cin >> q;
	vector<int> array(m);
	for(i=0;i<q;i++){
		cin >> num;
		int steps = 0;
		while(1>0){
			if(num==1){
				break;
			}
			else if(num%2==0){
				num = num / 2;
				steps++;
			}
			else if(num%3 == 0){
				num = (num*2) / 3;
				steps++;
			}
			else if(num%5 ==0){
				num = (num*4)/5;
				steps++;
			}
			else{
				steps = -1;
				break;
			}
		}
		cout << steps << endl;
	}
	
	return 0;
}