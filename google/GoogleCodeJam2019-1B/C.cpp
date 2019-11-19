#include <stdio.h> 
#include <iostream>
#include <map>
using namespace std;
void show_mem_rep(char *start, int n)  
{ 
    int i; 
    for (i = 0; i < n; i++) 
         printf(" %.2x", start[i]); 
    printf("\n"); 
} 
  
/*Main function to call above function for 0x01234567*/
int main() 
{ 
	int n,m,i=0,j=0,sum=0;
	cin >>n;
	int ans[1001];
	int array[n];
	for(i=0;i<n;i++){
		cin>>array[i];
	} 
	cin >> m;
	map<int,int> hashmap;
	int size[m], price[m];
	for(i=0;i<m;i++){
		cin >> size[i];
		hashmap[size[i]] = i;
	}
	cin >> m;
	for(i=0;i<m;i++){
		cin >> price[i];
	}

	ans[1] = price[hashmap[1]];
	for(i=2;i<=1000;i++){
		int minCost = 1000000000;
		for(j=i-1;j>=1;j--){
			if(hashmap.find(i-j)!=hashmap.end()){
				minCost = min(minCost, price[hashmap[i-j]] + ans[j]);
			}
		}
		if(hashmap.find(i)!=hashmap.end()){
			minCost = min(minCost, price[hashmap[i]]);
			//cout << "i = "<<i << "price[hashmap[i]] = " << price[hashmap[i]] << endl ;
		}
		ans[i] = minCost;
	}
	for(i=0;i<n;i++){
		sum = sum + ans[array[i]];
	}
	cout << sum << endl;
} 