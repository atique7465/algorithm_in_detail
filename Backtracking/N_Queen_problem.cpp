/// resource 01 : https://www.youtube.com/watch?v=xFv_Hl4B83A&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=64
/// resource 02 : https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
/// problem statement : The N Queen is the problem of placing N chess queens on an N×N chessboard so that no two queens attack each other.
/// time complexity : all the possible solutions, the best, average and worst case complexity remains O(N!)
///                   each time the branching factor decreases by 1 or more, but not much, hence the upper bound of O(N!)


#include<bits/stdc++.h>
#define mx 21
using namespace std;
int no_of_queens, LD[3*mx], RD[3*mx], col[mx], board[mx][mx], cnt = 1;

void Print_solutions()
{
	cout <<endl<< "Solution " << cnt << ":" << endl;
	for (int i = 1; i <= no_of_queens; i++)
	{
		for (int j = 1; j <= no_of_queens; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	cnt++;
}

bool n_queen(int Q)  /// assign queen row wise. Q defines current row number. 
{
	if (Q > no_of_queens)
	{
		Print_solutions();
		return true;
	}

	bool res = false;

	for (int C = 1; C <= no_of_queens; C++) /// check for all possible columns, so C for columns.
	{
		if (col[C] != 1 && LD[Q - C + no_of_queens] != 1 && RD[Q + C] != 1)
		{
			board[Q][C] = col[C] = LD[Q - C + no_of_queens] = RD[Q + C] = 1;
			
			res = n_queen(Q + 1) | res;

			board[Q][C] = col[C] = LD[Q - C + no_of_queens] = RD[Q + C] = 0; /// backtrack.
		}
	}
	return res;
}

int main()
{
	cout << "No. of queens : ";
	cin >> no_of_queens;

	if (!n_queen(1))
		cout <<endl<< "No solution found!" << endl;

	return 0;
}

/*
For how many solution possible : https://en.wikipedia.org/wiki/Eight_queens_puzzle

INPUT 01:
No. of queens : 1

Solution 1:
1

INPUT 02:
No. of queens : 2

No solution found!

INPUT 03:
No. of queens : 3

No solution found!

INPUT 04:
No. of queens : 4

Solution 1:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0

Solution 2:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

INPUT 05:
No. of queens : 6

Solution 1:
0 1 0 0 0 0
0 0 0 1 0 0
0 0 0 0 0 1
1 0 0 0 0 0
0 0 1 0 0 0
0 0 0 0 1 0

Solution 2:
0 0 1 0 0 0
0 0 0 0 0 1
0 1 0 0 0 0
0 0 0 0 1 0
1 0 0 0 0 0
0 0 0 1 0 0

Solution 3:
0 0 0 1 0 0
1 0 0 0 0 0
0 0 0 0 1 0
0 1 0 0 0 0
0 0 0 0 0 1
0 0 1 0 0 0

Solution 4:
0 0 0 0 1 0
0 0 1 0 0 0
1 0 0 0 0 0
0 0 0 0 0 1
0 0 0 1 0 0
0 1 0 0 0 0
*/