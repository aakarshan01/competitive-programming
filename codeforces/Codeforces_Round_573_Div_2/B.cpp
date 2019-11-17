#include <iostream>
#include <map>
#include <vector>
#include <set> 
#include <algorithm> 

using namespace std;

int main() {
	// your code goes here
	int ans = 2;

	vector<string> cards(3);
	cin >> cards[0] >> cards[1] >> cards[2];
	sort(cards.begin(), cards.end());

	if(cards[0].compare(cards[1]) == 0 && cards[1].compare(cards[2]) == 0)
	{
		ans = 0;
	}
	else if(cards[0][1] == cards[1][1] && cards[1][1] == cards[2][1] && cards[1][0] - cards[0][0] == 1 && cards[2][0] - cards[1][0] == 1)
	{
		ans = 0;
	}
	else if(cards[0].compare(cards[1]) == 0 || cards[1].compare(cards[2]) == 0 || cards[0].compare(cards[2]) == 0)
	{
		ans = 1;
	}
	else if(cards[0][1] == cards[1][1] && cards[1][0] - cards[0][0] <= 2)
	{
		ans = 1;
	}
	else if(cards[1][1] == cards[2][1] && cards[2][0] - cards[1][0] <= 2)
	{
		ans = 1;
	}
	else if(cards[0][1] == cards[2][1] && cards[2][0] - cards[0][0] <= 2)
	{
		ans = 1;
	}

	cout << ans << endl;
	return 0;
}