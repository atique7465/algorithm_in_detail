/*
idea :
    if (s1[i] == '\0')    
		return s2.size() - j;  ///base case. as string 01 is finished so remain characters of string o2 should be inserted to string 01.

	if (s2[j] == '\0')
		return s1.size() - i;  /// base case. as string 02 is finished so remain character of string 01 should be deleted.
    
    if (s1[i] == s2[j])
		ans = modified_LCS(i + 1, j + 1); /// as both are same so no need of operation
	else
		ans = 1 + min(modified_LCS(i, j + 1), min(modified_LCS(i + 1, j), modified_LCS(i+1, j+1))); /// as we need a operation so +1 &
		                                                                                            /// if replace then check i+1, j+1
		                                                                                            /// if delete then check i+1, j
		                                                                                            /// if insert then check i, j+1 and take the minimum of them.

*/

#include<bits/stdc++.h>
#define mxlength 2001
using namespace std;
int dp[mxlength][mxlength], t;
string s1, s2;

int modified_LCS(int i, int j)
{
	if (s1[i] == '\0')
		return s2.size() - j;

	if (s2[j] == '\0')
		return s1.size() - i;

	if (dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;

	if (s1[i] == s2[j])
		ans = modified_LCS(i + 1, j + 1);
	else
		ans = 1 + min( modified_LCS(i, j + 1), min( modified_LCS(i + 1, j), modified_LCS(i+1, j+1) ) );  

	return dp[i][j] = ans;
}



int main()
{
	scanf("%d", &t);

	while (t--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> s1 >> s2;
		printf("%d\n", modified_LCS(0, 0));
	}

	return 0;
}