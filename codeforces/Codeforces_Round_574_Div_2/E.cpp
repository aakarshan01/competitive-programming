#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#define P 998244353

using namespace std;
map <int,int>m;

long long int myPower(long long int a, long long int b)
{
	long long int ans = 1;
	while(b!=0)
	{
		ans = (ans * a)%P;
		b--;
	}
	return ans;
}

int main() {
	// your code goes here
	
	int n,l=0,i,j;
	cin >> n;
	vector<long long int> array(n);
	vector<long long int> array2(n);
	long long int sum = 0, prev = -1;

	for(i=0;i<n;i++)
	{
		cin >> array[i];
		array2[i] = array[i];
	}
	sort(array.begin(), array.end());
	sort(array2.begin(), array2.end());
	long long int temp = array[n-1];
	while(temp!=0)
	{
		l++;
		temp = temp / 10;
	}
	int sumArr[l];
	int added[10];
	int digitArray[n];
	for(i=0;i<10;i++)
	{
		added[i]=0;
	}
	for(i=0;i<array.size();i++)
	{
		temp = array[i];
		int digits = 0;
		while(temp!=0)
		{
			digits++;
			temp = temp / 10;
		}
		digitArray[i] = digits;
		for(j=digits;j<l;j++)
		{
			array[i] = array[i] + myPower(10,j);
			array2[i] = array[i];
			added[j]++;
		}
		//cout << array[i] << endl;
	}

	for(i=0;i<l;i++)
	{
		temp = 0;
		for(j=0;j<n;j++)
		{
			temp+= array[j]%10;
			array[j] = array[j]/10;
		}
		sumArr[i] = temp % P;
	}

	long long int ansRow[n];
	long long int oldCarry = 0;
	for(j=0;j<n;j++)
	{
		temp = 0;
		long long int currentNum = array2[j];
		for(i=0;i<2*l;i++)
		{
			if(i%2==0)
			{
				temp = (temp + (sumArr[i/2]*myPower(10,i))%P)%P;
			}
			else
			{
				temp = (temp + (((array2[j]%10) * myPower(10,i))%P * n)%P)%P ;
				array2[j] = array2[j] / 10;
			}
			cout << " j = " << j << " temp = " << temp << endl;
		}

		cout << temp << " " ;
		for(i=0;i<l;i++)
		{
			int x = l-i;
			temp = (temp + P - (added[i] * myPower(10,2*l-x))%P)%P;

		}
		cout << temp << " ";
		for(int x = digitArray[j]; x < l;x++)
		{
			temp = (temp + P - ((n-1) * myPower(10,l+x))%P)%P;
		}
		ansRow[j] = temp;
		cout << ansRow[j] << endl;
	}
	long long int finalAns = 0;
	for(j=0;j<n;j++){
		finalAns = (finalAns + ansRow[j])%P;
	}
	cout << finalAns << endl;
	return 0;
}