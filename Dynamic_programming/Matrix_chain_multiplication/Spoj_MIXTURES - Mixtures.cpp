#include<bits/stdc++.h>
#define mx 101
using namespace std;
int n, col[mx], dp[mx][mx], cumsum[mx];

int csum(int i, int j)
{
	return (cumsum[j] - cumsum[i - 1] ) % 100;
}

int min_computation(int beg, int end)
{
	if (beg >= end)
		return 0;

	if (dp[beg][end] != -1)
		return dp[beg][end];
    
	int res = INT_MAX;
	for (int mid = beg; mid < end; mid++)
	{
		 res = min( res , min_computation(beg, mid) + min_computation(mid + 1, end) + ( csum(beg, mid) * csum(mid+1, end) ) );
	}
	return dp[beg][end] = res;
}

int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) 
		{
			cin >> col[i];
			cumsum[i] = col[i] + cumsum[i - 1];
		}

		memset(dp, -1, sizeof(dp));

		cout << min_computation(1, n) << endl;
	}
	return 0;
}
