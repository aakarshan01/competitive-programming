#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,q,i,z,j,k;
	cin >> q;
	string s,t,p;
	while(q!=0)
	{
		cin >> n >> k;
		int ans = 1;

		//if(n%3==0)
		//	ans = 2;
		if(k%3==0)
		{
			int temp = k / 3; // 1
			int d = (temp-1)*3 + 4; // 4
			int multiple = n / d; // 1
			int nearest = d*multiple; // 4
			//if()
			//cout << d <<  " " << multiple << endl;
			
			//cout << temp << endl;
			/*if(temp == 1)
			{
				if(n%4 ==0)
					ans = 2;
			}
			else */if((n - nearest)%3 ==0 )
			{
				int temp1 = (n - nearest)/3;
				if(temp1 < temp)
					ans = 2;
			}	
		}
		else if(n%3==0)
		{
			ans = 2;
		}
		/*if(n%k==0)
			ans = 1;*/

		if(n==0)
			ans = 2;
		if(ans==1)
			cout << "Alice" << endl;
		else
			cout << "Bob" << endl;
		q--;
	}

	return 0;
}
