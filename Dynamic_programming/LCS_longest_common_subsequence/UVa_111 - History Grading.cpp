#include<bits/stdc++.h>
#define mxlength 21
using namespace std;
int dp[mxlength][mxlength], original[mxlength], student[mxlength],n;

int LCS(int i, int j)
{
	if (i > n || j > n)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;

	if (original[i] == student[j])
		ans = 1 + LCS(i + 1, j + 1);
	else
		ans = max(LCS(i, j + 1), LCS(i + 1, j));

	return dp[i][j] = ans;
}



int main()
{
	scanf("%d", &n);

	int value;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &value);
		original[value] = i;
	}

	while (1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (scanf("%d", &value) != 1)
				return 0;
			student[value] = i;
		}

		memset(dp, -1, sizeof(dp));

		printf("%d\n",LCS(1, 1));
	}
	
	return 0;
}