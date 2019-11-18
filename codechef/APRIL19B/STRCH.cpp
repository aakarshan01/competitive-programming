#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define SIZE 2002
int mod = 1000000007;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int calculateX(int vertical[][SIZE], int l, int r, int xIndex, int left, int right){
	int mid = (left + right) / 2;

	//cout << "xIndex = " << xIndex << " left = " << left << " mid = " << mid << " right = " << right << " vertical[r][mid] = " << vertical[r][mid] << " vertical[l-1][mid] = " << vertical[l-1][mid] << endl;
	if(vertical[r][mid]-vertical[l-1][mid] >= xIndex && vertical[r][mid-1] - vertical[l-1][mid-1] < xIndex){
		return mid;
	}
	else if(vertical[r][mid] - vertical[l-1][mid] < xIndex){
		return calculateX(vertical, l, r, xIndex, mid+1, right);
	}
	else{
		return calculateX(vertical, l, r, xIndex, left, mid);
	}
	//return 0;
}

int main() {
	// your code goes here
	int t, n, k, i, index = 0, j, size, x, xIndex, repeat,l ,r, f, cf;
	long ans = 0; 
	cin >> t;
	while(t>0){
		ans =0;
		cin >> n;
		vector<int> array(n+1);

		for(i=0;i<n+1;i++)
			array[i] = 0;
		char s[n+1];
		for(i=1;i<n+1;i++)
			cin >> s[i];
		
		char c;
		cin >> c;

		for(i=1;i<n+1;i++){
			//cout << s[i] << " " << c << endl;
			if(s[i]==c)
				array[i] = i;
			else{
				array[i] = array[i-1];
			}
		}
		

		for(i=1;i<n+1;i++)
			ans += array[i];
		
		cout << ans << endl;

		t--;
	}

	return 0;
}
	