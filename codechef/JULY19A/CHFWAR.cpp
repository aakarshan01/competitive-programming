#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <deque> 
using namespace std;

#define SIZE 2002
int mod = 1000000007;

class Node
{
	public :

	long long int val;
	bool boss;
	
	Node(long long int v, bool b)
	{
		val = v;
		boss = b;
	}
};

int main() {
	// your code goes here
	int t,j, n, k, i,r,c,m;
	long ans = 0;
	long long int f;

	cin >> t;
	while(t!=0){
		cin >> n;
		 deque <Node *> army; 
		 for(i=0;i<n-1;i++)
		 {
		 	cin >> m;
		 	Node* temp = new Node(m, false);
		 	army.push_back(temp);
		 }
		 cin >> f;
		 Node *newNode = new Node(0, true);
		 //army.insert(army.begin()+n-1,newNode);
		 int possible = 0;
		 vector <pair<long long int, int>> possibleAnswers;
		 for(i=1;i<n;i++)
		 {
		 	if(army.at((i)%(n-1))->val > f){
		 		continue;
		 	}
		 	//cout << "inserted at position i = " << i << " army.at((i)%(n-1))->val" << army.at((i)%(n-1))->val << endl;
		 	deque <Node *> currentArmy = army;
		 	currentArmy.insert(currentArmy.begin()+i, newNode);

		 	while(currentArmy.size() > 2)
		 	{
		 		Node *currentNode = currentArmy.front();
		 		if(currentNode->boss)
		 		{
		 			currentArmy.pop_front();
		 			currentArmy.push_back(currentNode);
		 		}
		 		else
		 		{
		 			currentArmy.pop_front();
		 			Node *nextNode = currentArmy.front();
		 			Node *nextNodeCopy = new Node(nextNode->val - currentNode->val,false);
		 			currentArmy.pop_front();

		 			if(nextNode->boss)
		 			{
		 				nextNodeCopy->boss = true;
		 				currentArmy.push_back(currentNode);
		 				currentArmy.push_back(nextNodeCopy);
		 			}
		 			else
		 			{
		 				currentArmy.push_back(currentNode);
		 			}
		 		}

		 		/*for(auto element:currentArmy)
			 	{
			 		cout << "( " << element->val << " , " << element->boss << " ) ,";
			 	}	
			 	cout << endl << "----------------" << endl;*/
		 	}
		 	if(currentArmy.front()->boss)
	 		{
	 			long long int temp = currentArmy.front()->val - f;
	 			possibleAnswers.push_back(make_pair(-temp,i+1));
	 		}
	 		else
	 		{
	 			long long int temp = currentArmy.back()->val - f;
	 			possibleAnswers.push_back(make_pair(-temp,i+1));
	 		}
		 }
		 if(possibleAnswers.size() == 0)
		 {
		 	cout << "impossible" << endl;
		 }
		 else
		 {
		 	cout << "possible" << endl;
		 	sort(possibleAnswers.begin(), possibleAnswers.end());
		 	cout << possibleAnswers[0].second << " " << possibleAnswers[0].first<<endl;
		 }
		 
		t--;
	}
	return 0;
}
	