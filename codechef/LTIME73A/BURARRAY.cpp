#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t,x,j,u,v,type,Q;
	long long int n,s=0,y,p,q;
	register int i;
	long long int k;
	cin >> t ;
	map<long long int, int> m;

	while(t!=0){
		//cin  >> n >> x >> k;
		scanf("%lld", &n);
		scanf("%d", &Q);
		for(i=0;i<Q;i++)
		{
			//cout << "yo " << endl;
			scanf("%d", &type);
			if(type == 1)
			{
				scanf("%lld", &y);
				m[y+s] = 1;
			}
			else
			{
				scanf("%lld", &p);
				scanf("%lld", &q);
				long long int l = p + s, r = q + s;
				//cout << " l = " << l << " r = " << r << endl;
				if(m.find(r)==m.end())
				{
					//cout << "yo3.1" << endl; 
					k = r;
				}
				else if (m.find(l) != m.end() && distance(m.find(l), m.find(r)) == r - l)
				{
					//cout << "yo3.2 " << endl;
					k = 0;
				}
				else
				{
					//cout << "yo3.3 " << endl;
					long long int min = l;
					long long int max = r;
					int sub = 1;
					while(min<max)
					{

						//cout << " min = " << min << " max = " << max << endl;
						long long int mid = min + (max-min)/2;
						//long long int temp = m.find(r) - m.find(mid);
						if(m.find(mid)==m.end())
						{
							min = mid + 1;
						}
						else
						{
							if(distance(m.find(mid), m.find(r)) == r - mid)
							{
								max = mid - 1;
								sub=0;
							}
							else
							{
								min = mid + 1;
							}
						}
					}
					if(min == max)
						k = min - 1;
					if(sub==0)
						k = k + 1;
				}

				s=(s + k)%n;
				cout << k << endl;
			}
			//cout << " i = " << i << " q = " << q << endl;
		}
		
		t--;
	}
	return 0;
}
	