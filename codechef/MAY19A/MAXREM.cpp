#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int mod = 1000000007;
int array[100005];
int arraySize = 0;

bool comparator(const pair<int, int> &a, const pair<int, int> &b){
	return a.second<b.second;
}

int calculateX(int start){
	int i, ctr = 1, x = 0;
	for(i=start;i<arraySize;i++){
		x += array[i] / ctr;
		ctr++;
	}
	return x;
}

int calculateAns(int k, int left, int right){
	int mid = (left + right) / 2;

	//cout << "xIndex = " << xIndex << " left = " << left << " mid = " << mid << " right = " << right << " vertical[r][mid] = " << vertical[r][mid] << " vertical[l-1][mid] = " << vertical[l-1][mid] << endl;
/*	if(vertical[r][mid]-vertical[l-1][mid] >= xIndex && vertical[r][mid-1] - vertical[l-1][mid-1] < xIndex){
		return mid;
	}
	else if(vertical[r][mid] - vertical[l-1][mid] < xIndex){
		return calculateX(vertical, l, r, xIndex, mid+1, right);
	}
	else{
		return calculateX(vertical, l, r, xIndex, left, mid);
	}*/
	return 0;
}

int main() {
	// your code goes here
	int t, n, k, i, index = 0, j, size, x, xIndex, repeat,l ,r, f, cf, ans = 0;

	cin>>n;
	vector<int> array(n);

	for(i=0;i<n;i++){
		cin>>array[i];
	}
	sort(array.begin(), array.end());


	for(i=n-2;i>=0;i--){
		if(array[i]!=array[n-1])
			break;
	}
	cout << array[i] % array[n-1] << endl;
}
	