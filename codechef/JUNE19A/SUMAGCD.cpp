#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>
#include <iomanip> 
#include <map>
#include <set>
using namespace std;

map<string, long long int> m;
	
int gcd(int a,int b){
	if(b==0){
		return a;
	} 
	return gcd(b,a%b);

}
int main() {
	// your code goes here
	
	int t,n,i;
	cin >> t;
	while(t!=0){
		cin >> n;
		
		set<int> s;
		for(i=0;i<n;i++){
			int num;
			cin>>num;
			s.insert(num);
		}
		int l = s.size();

		vector<int> array(l);
		i=0;
		for(auto it : s){
			array[i++] = it;
		}

		if(l==1){
			cout << array[0] + array[0] << endl;
			t--;
			continue;
		}
		sort(array.begin(), array.end());

		int gcdArray = array[0];
		for(i=0;i<l;i++){
			gcdArray = gcd(gcdArray, array[i]);
		}
		if(gcdArray>1){
			for(i=0;i<l;i++)
			array[i] = array[i]/gcdArray;		
		}


		int prefix[l];
		int suffix[l];
		prefix[0] = array[0]; suffix[l-1] = array[l-1];
		for(i=1;i<l;i++)
			prefix[i] = gcd(array[i], prefix[i-1]);
		for(i=l-2;i>=0;i--)
			suffix[i] = gcd(array[i], suffix[i+1]);
		int max = 0;
		for(i=0;i<l;i++){
			int temp1 = array[i];
			int temp2 = 0;
			if(i==0)
				temp2 = suffix[i+1];
			else if(i==l-1)
				temp2 = prefix[i-1];
			else 
				temp2 = gcd(prefix[i-1],suffix[i+1]);
			if(temp1+temp2>max){
				max = temp1 + temp2;
				//cout << " i = " << i << " max = " << max << " temp1 = " << temp1 << " temp2 = " << temp2 << endl;
			}
		}
		cout << gcdArray*(max) << endl;
		t--;
	}


	return 0;
}
