#include <iostream>
#include <algorithm>
#include <vector>

#include <set> 
#include <iterator> 
#include <cmath>
//using namespace __gnu_pbds;
using namespace std;
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}
 
vector<int>r;

void generate(int num, int n){
	if(num>=1000000000)
		return;
	int temp1 = num*10 + 1;
	int temp2 = num*10 + 3;
	int temp3 = num*10 + 5;
	//cout << temp1 << endl;
	if(temp1<=n){
		r.push_back(temp1);
		generate(temp1, n);
	}
	else{
		return;
	}
	if(temp2<=n){
		r.push_back(temp2);
		generate(temp2, n);
	}
	else{
		return;
	}
	if(temp3<=n){
		r.push_back(temp3);
		generate(temp3, n);
	}
	else{
		return;
	}
} 
void printVector(){
	int i = 0;
	for(i = 0;i<r.size();i++){
		cout << r[i] << " " ;
	}
	cout << endl;
}

int main() {
	// your code goes here
	int j,t,n,q,i;
	long long int x;
	//cin >> t;
	long long int m;
	cin >> n;
	generate(0,n);
	//sort(r.begin(), r.end());
	cout << r.size() << endl;
	//printVector();
	return 0;
}
	