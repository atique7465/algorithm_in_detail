/// resource : http://www.shafaetsplanet.com/?p=1862
/// time complexity : O ( length1 * length2 )

#include<bits/stdc++.h>
#define mxlength 1001
using namespace std;
int dp[mxlength][mxlength];
string s1, s2;

int LCS(int i, int j)
{
	if (s1[i] == '\0' || s2[j] == '\0')
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;

	if (s1[i] == s2[j])
		ans = 1 + LCS(i + 1, j + 1);
	else
		ans = max(LCS(i, j + 1), LCS(i + 1, j));

	return dp[i][j] = ans;
}


string str = "";
void LCS_print(int i, int j)    /// this function will take too much time as it prints all possible LCS.
{
	if (s1[i] == '\0' || s2[j] == '\0')
	{
		cout << str << endl;
		return;
	}

	if (s1[i] == s2[j])
	{
		str.push_back(s1[i]);
		LCS_print(i + 1, j + 1);
		str.pop_back();
	}
	else
	{
		if (dp[i][j + 1] != dp[i + 1][j])
		{
			if (dp[i][j + 1] > dp[i + 1][j])
				LCS_print(i, j + 1);
			else
				LCS_print(i + 1, j);
		}
		else
		{
			LCS_print(i, j + 1);
			LCS_print(i + 1, j);
		}
	}
}

int main()
{
	cout << "Enter the strings : " << endl;
	cin >> s1 >> s2;

	memset(dp, -1, sizeof(dp));

	cout << "length of LCS is : " << LCS(0, 0) << endl;
	LCS_print(0, 0);

	return 0;
}

/*
HELLOM
HMLLD

HELLO
LOXHE
*/
