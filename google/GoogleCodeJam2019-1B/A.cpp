#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int t,p,q,x,y,i,n,k,l,r;
	char c;

	long long int ctr = 0;
	cin >> t;
	int caseNo = 1;
	while(t!=0){
		ctr = 0;
		cin >> n >> k;
		int cArray[n];
		int dArray[n];

		for(i=0;i<n;i++){
			cin >> cArray[i];
		}
		for(i=0;i<n;i++){
			cin >> dArray[i];
		}
		ctr = 0;
		for(l=0;l<n;l++){
			for(r=l;r<n;r++){

				int maxC = 0;
				int maxD = 0;
				for(i=l;i<=r;i++){
					if(cArray[i] > maxC)
						maxC = cArray[i];
					if(dArray[i] > maxD)
						maxD = dArray[i];
				}
				if(abs(maxC-maxD) <= k)
					ctr++;
			}
		}


		cout << "Case #" << caseNo << ": " << ctr << endl;
		t--;
		caseNo++;
	}
}
