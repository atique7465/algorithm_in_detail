/// resource 01: https://www.youtube.com/watch?v=kyLxTdsT8ws&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=65
/// problem statement : Subset sum problem is to find subset of elements that are selected from a given set
///                     whose sum adds up to a given number K. coin change algo mainly with all solutions.
/// time complexity O(2^n). for one solution we can use coin change dp with O(n*amount) time complexity.

#include<bits/stdc++.h>
#define mx  21
using namespace std;
int coins[mx], amount, no_of_coins, cnt = 1;
vector<int>selected;

void print_selected()
{
	cout << endl << "Soution " << cnt << " :" << endl;
	for (int i = 0; i < selected.size(); i++)
		cout << selected[i] << " ";
	cout << endl;
	cnt++;
}

bool coin_change(int i, int make)
{
	if (i > no_of_coins)
	{
		if (make == 0)
		{
			print_selected();
			return true;
		}
		else
			return false;
	}

	int status1 = 0, status2 = 0;
	if (make - coins[i] >= 0)
	{
		selected.push_back(coins[i]);
		status1 = coin_change(i + 1, make - coins[i]);
		selected.pop_back();  /// backtrack.
	}

	status2 = coin_change(i + 1, make);

	return status1 | status2;
}

int main()
{
	cout << "Number of coins : ";
	cin >> no_of_coins;
	cout << "enter the coins : ";
	for (int i = 1; i <= no_of_coins; i++)
		cin >> coins[i];

	cout << "Enter the amount : ";
	cin >> amount;
	if (!coin_change(1, amount))
		cout <<endl<< "Not Possible!"<<endl;

	return 0;
}

/*
INPUT 01:
Number of coins : 6
enter the coins : 5 10 12 13 15 18
Enter the amount : 30

Soution 1 :
5 10 15

Soution 2 :
5 12 13

Soution 3 :
12 18

INPUT 02: 
Number of coins : 5
enter the coins : 5 8 11 15 18
Enter the amount : 23

Soution 1 :
5 18

Soution 2 :
8 15
*/
