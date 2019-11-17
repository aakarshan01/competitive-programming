#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	int n,i,j,k;
	string initialString, firstStringResult, secondStringResult, thirdStringResult;
	cin >> n;
	string s;
	string ans,ans2;
	int frequencyTable[26];
	
	for(i=0;i<n;i++){
		//cout <<"yo " << endl;
		ans="";
		ans2="";
		for(j=0;j<26;j++)
			frequencyTable[j]=0;

		cin >> s;
		for(j=0;j<s.length();j++){
			frequencyTable[s[j]-'a']++;
			//cout << frequencyTable[j] << " " ;
		}	
		//cout << "yo" << endl;
		int in = 0;
		for(j=0;j<26;j++){
			if(frequencyTable[j]>0){
				if(in%2==1){
					for(k=0;k<frequencyTable[j];k++){
						char c = 'a' + j;
						ans=ans+c;
					}

				}
				in++;
			}
		}
		in = 0;
		for(j=0;j<26;j++){
			if(frequencyTable[j]>0){
				if(in%2==0){
					for(k=0;k<frequencyTable[j];k++){
						char c = 'a' + j;
						ans=ans+c;
					}

				}
				in++;
			}
		}

		in = 0;
		for(j=0;j<26;j++){
			if(frequencyTable[j]>0){
				if(in%2==0){
					for(k=0;k<frequencyTable[j];k++){
						char c = 'a' + j;
						ans2=ans2+c;
					}

				}
				in++;
			}
		}
		in = 0;
		for(j=0;j<26;j++){
			if(frequencyTable[j]>0){
				if(in%2==1){
					for(k=0;k<frequencyTable[j];k++){
						char c = 'a' + j;
						ans2=ans2+c;
					}

				}
				in++;
			}
		}
		int type=0;
		for(j=1;j<ans.length();j++){
			if(abs(ans[j]-ans[j-1]) == 1)
			{
				type++;
				break;
			}
		}
		if(type==1){
			for(j=1;j<ans2.length();j++){
				if(abs(ans2[j]-ans2[j-1]) == 1)
				{
					type++;
					break;
				}
			}
		}
		if(type==0)
			cout << ans << endl;
		else if(type==1)
			cout << ans2 <<endl;
		else
			cout<<"No answer"<<endl;
	}
	return 0;
}
