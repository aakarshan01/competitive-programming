#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// your code goes here
	
	int n,k, goLeft = 0,i,ans = -1,j;
	cin >> n;

	vector<int> array(n+1);
	int frequency[1000000];

	for(i=0;i<1000000;i++)
		frequency[i] = 0;

	for(i=1;i<=n;i++){
		cin >> array[i];
		frequency[array[i]]++;
	}
	int maxNumber = 0;
	for(i=0;i<1000000;i++){
		if(frequency[i]>frequency[maxNumber])
			maxNumber = i;
	}
	
	int firstOccurence = 0;
	for(i=1;i<=n;i++){
		if(array[i] == maxNumber){
			firstOccurence = i;
			break;
		}
	}
	//cout << "maxNumber = " << maxNumber << " firstOccurence = " << firstOccurence << " " << frequency[8] << endl;
	i = firstOccurence;
	j = firstOccurence - 1;

	int steps[1000000][3];
	int ctr=0;

	while(j>0){
		if(array[j] < maxNumber){
			steps[ctr][0] = 1;
		}
		else{
			steps[ctr][0] = 2;
		}
		steps[ctr][1] = j;
		steps[ctr][2] = i;
		ctr++;
		i--;
		j--;
	}

	i = firstOccurence;
	j = firstOccurence + 1;
	while(j<=n){
		if(array[j] == maxNumber){

		}
		else if (array[j] < maxNumber){
			steps[ctr][0] = 1;
			steps[ctr][1] = j;
			steps[ctr][2] = i;
			ctr++;
		}
		else{
			steps[ctr][0] = 2;
			steps[ctr][1] = j;
			steps[ctr][2] = i;
			ctr++;	
		}

		i++;
		j++;
	}
	cout << ctr << endl;
	for(i=0;i<ctr;i++){
		cout << steps[i][0] << " " << steps[i][1] << " " << steps[i][2] << endl; 
	}
	

	return 0;
}