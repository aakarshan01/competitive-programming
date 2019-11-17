#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	
	long long int x;
	cin >> x;

	if(x%4==0)
	{
		cout << "1 A" << endl;
	}
	else if(x%4==1)
	{
		cout << "0 A" << endl;
	}
	else if(x%4==2)
	{
		cout << "1 B" << endl;
	}
	else
	{
		cout << "2 A" << endl;
	}

	return 0;
}