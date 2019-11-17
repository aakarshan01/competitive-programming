#include <iostream>
#include <map>
#include <vector>
#include <stack>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,i,j=0;
	long long int k;
	long long int overflow = 4294967295;
	long long int current = 1;
	int size = 0;
	long long int ans = 0;

	cin >> n;
	stack<long long int> st;
	string s;
	int flag = 0;

	while(n!=0){
		cin >> s;

		if(s[0] == 'f'){
			cin >> k;
			st.push(k);
			if(flag == 0){
				if(current * k <= overflow){
					current = current * k;
				}
				else{
					flag = 1;
					size++;
				}
			}
			else{
				size++;
			}
		}
		else if(s[0] == 'e'){
			k = st.top();
			st.pop();
			if(flag == 1){
				size--;
				if(size==0)
					flag = 0;
			}
			else{
				//cout << " k = " << k << endl;
				current = current / k;
			}
		}
		else{
			if(flag==1){
				j = -1;
				break;
			}
			else{
				//cout << " current = " << current << endl;
				ans+=current;
			}
			if(ans > overflow){
				j=-1;
				break;
			}
		}
		n--;
		//cout << ans << endl;
	}
	if(j==-1){
		cout << "OVERFLOW!!!" << endl;
		/*n--;
		while(n!=0){	
			cin >> s;
			n--;
		}*/
	}
	else{
		cout << ans << endl;
	}


	return 0;
}