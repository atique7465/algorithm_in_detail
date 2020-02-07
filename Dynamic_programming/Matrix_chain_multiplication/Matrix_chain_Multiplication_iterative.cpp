/// resource 01: https://www.youtube.com/watch?v=_WncuhSJZyA&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=51
/// time complexity O(n^3).

#include<bits/stdc++.h>
#define mx 101
using namespace std;
int n, row[mx], col[mx], dp[mx][mx], bracket[mx][mx];

int min_computation()
{
	for (int M = 1; M <= n; M++)
	{
		int i = 1;
		int j = M;

		while (j <= n)
		{
			if (i == j)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = INT_MAX;
				for (int mid = i; mid < j; mid++)
				{
					int New = dp[i][mid] + dp[mid + 1][j] + (row[i] * col[mid] * col[j]);
					if (New < dp[i][j])
					{
						dp[i][j] = New;
						bracket[i][j] = mid; /// for bracketing.
					}
				}
			}
			i++;
			j++;
		}
	}
	return dp[1][n];
}


void separation()
{
	int i = n;
	while (1)
	{
		cout << bracket[1][i] <<" ";
		i = bracket[1][i];
		if (i <= 2)
			break;
	}
}

int main()
{
	cout << "How many matrix :" << endl;
	cin >> n;
	cout << "Enter the dimensions : " << endl;
	for (int i = 1; i <= n; i++)
		cin >> row[i] >> col[i];

	cout << "Minimum computation nedded : " << min_computation() << endl;
	cout << "The separation points are : ";
	separation();

	return 0;
}

/*
INPUT 01:
How many matrix :
4
Enter the dimensions :
3 2
2 4
4 2
2 5
Minimum computation nedded : 58
The separation points are : 3 1
INPUT 02:
How many matrix :
3
Enter the dimensions :
10 100
100 5
5 50
Minimum computation nedded : 7500
The separation points are : 2
*/
