#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
map <int,int>m;

int main() {
	// your code goes here
	
	int n;
	cin >> n;
	vector<int> array(n);
	int winner = 1,end=0;
	long long int sum = 0, prev = -1;

	for(int i=0;i<n;i++)
	{
		cin >> array[i];
		if(m.find(array[i]) == m.end())
		{
			m[array[i]] = 1;
		}
		else
		{
			m[array[i]]++;
		}
		if(m[array[i]] == 3)
		{
			winner = 2;
			end = 1;
		}
		else if(end == 0 && m[array[i]] == 2 && m.find(array[i]-1) != m.end())
		{
			winner = 2;
			end = 1;
		}
		else if(end == 0 && m[array[i]] == 2)
		{
			if(prev == -1)
			{
				prev = m[array[i]];
			}
			else if(array[i] != prev)
			{
				winner = 2;
				end = 1;
			}
		}
		//cout << "end = " << end << " winner = " << winner << endl;
	
		sum+=array[i];
	}
	if(end == 0 && m.find(0)!=m.end())
	{
		//cout << "yo" << endl;
		if(m[0] == n)
		{
			winner = 2;
			end = 1;
		}
		else if(m[0] == 2)
		{
			winner = 2;
			end = 1;
		}
		else if(sum%2==1)
		{
			winner =2;
			end = 1;
		}
		else
		{
			winner = 1;
			end = 1;
		}
	}
	sort(array.begin(), array.end());
	long long int difference = 0;
	for(int i = 0;i<n-1;i++)
		difference += array[i+1] - array[i] - 1;
	if(end == 0)
	{
		if(n==1)
		{
			if(sum%2 == 0)
				winner = 2;
			else
				winner = 1;
		}
		else if((n%2 == 1 && difference%2==0) || (n%2 == 0 && difference%2 == 1))
		{
			winner = 1;
		}
		else
		{
			winner = 2;
		}
		if(prev!=-1)
		{
			if(winner == 1)	
				winner = 2;
			else
				winner = 1;
		}
		end = 1;
	}

	if(winner == 1)
	{
		cout << "sjfnb"<<endl;
	}
	else
	{
		cout << "cslnb" << endl;
	}
	

	return 0;
}