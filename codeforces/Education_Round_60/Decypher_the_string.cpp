#include <iostream>
#include <map>
#include <vector>

using namespace std;

map <vector<int>, int> m;

int main() {
	// your code goes here
	string initialString, firstStringResult, secondStringResult, thirdStringResult;
	cin >> initialString;
	
	int i,length = initialString.length();
	char firstString[length + 1];
	char secondString[length + 1];
	char thirdString[length + 1];
	
	for(i = 0; i<length;i++){
	    char temp = 'a';
	    firstString[i] = temp + i % 26;
	    secondString[i] = temp + (i / 26) % 26;
	    thirdString[i] = temp + (i / 576) % 26;

	    vector<int> temp1;
	    temp1.push_back(firstString[i]);
	    temp1.push_back(secondString[i]);
	    temp1.push_back(thirdString[i]);
	    m[temp1] = i;
	}
	firstString[i] = secondString[i] = thirdString[i] = '\0';

	cout << "? " << firstString << endl;
	cin >> firstStringResult;
	cout << "? " << secondString << endl;
	cin >> secondStringResult;
	cout << "? " << thirdString << endl;
	cin >> thirdStringResult;

	int mapping[length];
	for(i = 0; i< length; i++){
		vector<int> temp2;
		temp2.push_back(firstStringResult[i]);
		temp2.push_back(secondStringResult[i]);
		temp2.push_back(thirdStringResult[i]);
		mapping[i] = m[temp2];

		//cout << "original index = " << mapping[i] << "transformed inex = " << i << endl;
	}
	char outputString[length + 1];

	for(i = 0; i < length; i++){
		outputString[mapping[i]] = initialString[i];
	}
	outputString[i] = '\0';
	cout << "! " << outputString << endl;
	//cout << "firstString = " << firstString << endl << "secndString = " << secondString << endl << "thirdString = " << thirdString << endl;
	
	return 0;
}
