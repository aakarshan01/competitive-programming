#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

map<int, int> m;
map<int, int> m1;
map<int, int> m2;
bool primeArray[2750132];

void sieve(int n){
	int i=0,temp=0;
	for(i=0;i<=n;i++){
		primeArray[i]=true;
		//cout << "i" << endl;
	}
	for(temp=2;temp*temp<=n;temp++){
		if(primeArray[temp]==true){
			for(i=temp*temp;i<=n;i+=temp){
				primeArray[i]=false;
			}
		}
	}
	int current = 1;
	for(i=2;i<=n;i++){
		if(primeArray[i]==true){
			m[i]=current;
			current++;
		}
	}
	return;
}

int greatestDivisor(int n) 
{ 
    if(n%2==0)
  		return n/2;
  	if(n%3==0)
  		return n/3;
    for (int i=5; i*i<=n; i=i+6) {
        if (n%i == 0){
        	return n/i;
        } 
        else if(n%(i+2) == 0){
        	return n/(i+2);
        } 
    } 
} 

int main() {

	int i,j,n;
	cin >> n;
	int arrayB[2*n];
	vector<int> arrayAns;
	vector<int> arrayC;
	vector<int> arrayD;
	vector<int> arrayE;

	for(i=0;i<2*n;i++){
		cin >> arrayB[i];
	}
	sieve(2750131);	

	for(i=0;i<2*n;i++){
		if(m.find(arrayB[i]) == m.end()){
			arrayAns.push_back(arrayB[i]);
			int temp = greatestDivisor(arrayB[i]);
			//cout << " temp = " << temp << endl;
			if(m1.find(temp) == m1.end()){
				m1[temp] = 1;
			}
			else{
				m1[temp]++;
			}
		}
		else{
			arrayD.push_back(arrayB[i]);
		}
	}


	for(i=0;i<arrayD.size();i++){
		if(m1.find(arrayD[i])!=m1.end()){
			//cout << arrayD[i] << " yo " ;
			
			if(m1[arrayD[i]]>0){
				//cout << arrayD[i] << " yo " ;
				m1[arrayD[i]]--;
			}
			else{
				arrayE.push_back(arrayD[i]);
				int temp = arrayD[i];
				if(m2.find(temp) == m2.end()){
					m2[temp] = 1;
				}
				else{
					m2[temp]++;
				}
			}
		}
		else{
			arrayE.push_back(arrayD[i]);
			int temp = arrayD[i];
			if(m2.find(temp) == m2.end()){
				m2[temp] = 1;
			}
			else{
				m2[temp]++;
			}
		}
	}

	sort(arrayE.begin(), arrayE.end());

	for(i=0;i<arrayE.size();i++){
		cout << arrayE[i] << " " ;
	}
	cout << endl;

	for(i=arrayE.size()-1;i>=0;i--){
		int temp = arrayE[i];
		if(m2.find(temp)!=m2.end()){
			if(m2[temp] > 0){
				int temp1 = m[temp];
				m2[temp]--;
				m2[temp1]--;
				arrayAns.push_back(temp1);
			}
		}
	}
	for(i=0;i<arrayAns.size();i++){
		cout << arrayAns[i] << " " ;
	}
	cout << endl;
	return 0;
}