#include<bits/stdc++.h>
#define mxlength 101
using namespace std;
int dp[mxlength][mxlength], t;
string s1, s2, output[mxlength][mxlength];

void LCS(int ln1, int ln2)
{
	for (int i = 0; i <= ln1; i++)
	{
		for (int j = 0; j <= ln2; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
				output[i][j] = "";
			}

			else if (s1[i-1] == s2[j-1])
			{
				dp[i][j] = 1 + dp[i - 1][j - 1];
				output[i][j] = output[i - 1][j - 1] + s1[i-1];
			}

			else if (dp[i - 1][j] > dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
				output[i][j] = output[i - 1][j];
			}
			
			else if (dp[i][j-1] > dp[i-1][j])
			{
				dp[i][j] = dp[i][j - 1];
				output[i][j] = output[i][j - 1];
			}

			else
			{
				dp[i][j] = dp[i - 1][j];
				output[i][j] = min(output[i - 1][j], output[i][j - 1]); /// as length are same so take the previus string which is lexicographically smaller.
			}
		}
	}
}


int main()
{	
	int cas = 1;
	scanf("%d", &t);

	while (cas <= t)
	{
		memset(dp, -1, sizeof(dp));
		cin >> s1 >> s2;
		int ln1 = s1.size();
		int ln2 = s2.size();
		LCS(ln1, ln2);

		printf("Case %d: ", cas);

		if (dp[ln1][ln2] == 0)
			printf(":(");
		else
			cout << output[ln1][ln2];

		printf("\n");

		cas++;
	}

	return 0;
}