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
  
int main() {
	// your code goes here
	int j,t,n,q,i;
	long long int x;
	scanf("%d",&t);
	//cin >> t;
	long long int m;
	
	while(t!=0){
		scanf("%lld",&m);
		//cin >> m;

		//tree<int, null_type,less<int>, rb_tree_tag,tree_order_ answers;
		vector<long long int> factors;
		vector<long long int> answersVector;
		for(x=1;x*x<=m;x++){
			if(m%x==0){
				if(m/x==x){
					factors.push_back(x);
				}
				else{
					factors.push_back(x);
					factors.push_back(m/x);
				}
			}
		}
		sort(factors.begin(), factors.end());
		set<long long int> answers;
		for(i=0;i<factors.size();i++){
			for(j=i;j<factors.size();j++){
				if(log10(factors[i])+log10(factors[j]) <= 14){
					long long int num = factors[i]*factors[j];
					if(num<=m){
						//cout << num << endl;
						answers.insert(m+num);
					}
				}
				else{
					break;
				}
			}
		}
		
		set <long long int> :: iterator itr; 
   		for (itr = answers.begin(); itr != answers.end(); ++itr) 
    	{ 
        	answersVector.push_back(*itr); 
    	}
		sort(answersVector.begin(), answersVector.end()); 

		printf("%d\n",answersVector.size());
		for (i=0;i<answersVector.size();i++) 
    	{ 
        	printf("%lld\n",answersVector[i]); 
    	}

		t--;
	}
	return 0;
}
	