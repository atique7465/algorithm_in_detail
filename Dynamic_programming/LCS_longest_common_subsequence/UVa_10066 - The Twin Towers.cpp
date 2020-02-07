#include<bits/stdc++.h>
#define mxlength 101
using namespace std;
int dp[mxlength][mxlength],t1[mxlength], t2[mxlength],n1,n2;

int LCS(int i, int j)
{
	if (i >= n1 || j >= n2)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;

	if (t1[i] == t2[j])
		ans = 1 + LCS(i + 1, j + 1);
	else
		ans = max(LCS(i, j + 1), LCS(i + 1, j));

	return dp[i][j] = ans;
}

int main()
{
	int cas = 1;
	while (cin >> n1 >> n2)
	{
		if (n1 == 0 && n2 == 0)
			break;

		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n1; i++)
			cin >> t1[i];

		for (int i = 0; i < n2; i++)
			cin >> t2[i];

		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",cas,LCS(0, 0));
		cas++;
	}

	return 0;
}
