/// resource 01: http://www.shafaetsplanet.com/planetcoding/?p=1885
/// time complexity O(n^3).

#include<bits/stdc++.h>
#define mx 101
using namespace std;
int n, row[mx], col[mx], dp[mx][mx], bracket[mx][mx];

int min_computation(int beg, int end)
{
	if (beg >= end)
		return 0;

	if (dp[beg][end] != -1)
		return dp[beg][end];
    
	int res = INT_MAX;
	for (int mid = beg; mid < end; mid++)
	{
		int New = min_computation(beg, mid) + min_computation(mid + 1, end) + (row[beg] * col[mid] * col[end]);
		if (New < res)
		{
			res = New;
			bracket[beg][end] = mid;  /// for geting separation points;
		}
	}
	return dp[beg][end] = res;
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

	memset(dp, -1, sizeof(dp));

	cout << "Minimum computation nedded : " << min_computation(1, n) << endl;
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