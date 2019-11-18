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
	int t, n, k, i, index = 0, j, size, x, xIndex, repeat,l ,r, f, cf, ans = 0;

	cin >> t;
	while(t--){
		ans = 0;
		index = 0;
		cin >> n >> k;
		int array[n];
		for(int i=0;i<n;i++){
			cin >> array[i];
			//array[i]--;
		}
		int matrix[n+1][SIZE];
		int vertical[n+1][SIZE];
		for(i=0;i<n+1;i++){
			for(j=0;j<SIZE;j++){
				matrix[i][j] = 0;
				vertical[i][j] = 0;
			}
		}
		for(i=1;i<n+1;i++){
			int num = array[i-1];
			matrix[i][num]++;
		}
		for(i=1;i<n+1;i++){
			for(j=0;j<SIZE;j++){
				matrix[i][j] = matrix[i-1][j] + matrix[i][j];
			}
		}
		/*
		for(i=0;i<n + 1;i++){
			for(j=0;j<10;j++){
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cout << "-------------------------------------" << endl;
		*/
		for(i=1;i<n+1;i++){
			for(j=1;j<SIZE;j++){
				vertical[i][j] = vertical[i][j-1] + matrix[i][j];
			}
		}
		/*
		for(i=0;i<n + 1;i++){
			for(j=0;j<10;j++){
				cout << vertical[i][j] << " ";
			}
			cout << endl;
		}		
		cout << "-------------------------------------" << endl;
		*/		
		int dataSize = (n*(n+1)) / 2;
		int data[dataSize][3];

		for(i=1;i<n+1;i++){
			for(j=1;j<=i;j++){
				data[index][0] = j;		// ..l
				data[index][1] = i;		// ..r

				//cout << j << " " << i << endl;
				index++;
			}
		}

		//cout << "index = " << index << " dataSize = " << dataSize << endl;
		
		for(i=0;i<dataSize;i++){
			l = data[i][0];
			r = data[i][1];
			size = r - l + 1;
			repeat = ceil(k / (1.0 * size) );
			xIndex = r - (((size * repeat) - k) / repeat) - l + 1; // starting from l
			
			//if(l==r)
			//	x=array[xIndex-1];
			//else
			//	cout << calculateX(vertical, l, r, xIndex, 0, SIZE-1) << endl;
			//x = array[xIndex-1];
			//cout << xIndex << endl;
			x = calculateX(vertical, l, r, xIndex, 0, SIZE-1);
			f = matrix[r][x] - matrix[l-1][x];

			cf = matrix[r][f] - matrix[l-1][f];
			if(cf > 0)
				ans++;
			//cout << "l = " << l << " r = " << r << " repeat = " << repeat << " xIndex = " << xIndex << " x = " << x << " f = " << f << " cf = " << cf << endl;
		}
		cout << ans << endl;
	}

	return 0;
}
	