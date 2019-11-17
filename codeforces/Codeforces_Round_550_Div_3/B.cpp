#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// your code goes here
	int n,k, goLeft = 0,i;
	cin >> n;

	vector<int> odd;
	vector<int> even;


	for(i=0;i<n;i++){
		cin >> k;
		if(k%2 == 0)
			even.push_back(k);
		else
			odd.push_back(k);
	}
	int removeN = even.size() < odd.size() ? even.size() : odd.size();
	
	sort(odd.begin(),odd.end(), greater<int>());
	sort(even.begin(),even.end(), greater<int>());

	//cout << "removeN =" << removeN << endl;
	for(i=0;i<removeN;i++){
		odd.erase(odd.begin());
		even.erase(even.begin());
	}
	//cout << "removeN =" << removeN << "odd.size() = " << odd.size() << "even.size() = " << even.size() << endl;
	int ans = 0;

	if(odd.size() > 0){
		for(i=1;i<odd.size();i++)
			ans+=odd[i];
	}
	else{
		for(i=1;i<even.size();i++)
			ans+=even[i];
	}
	cout << ans << endl;
	//cout << "up " << endl; 
	return 0;
}