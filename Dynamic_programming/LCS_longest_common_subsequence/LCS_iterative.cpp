/// resource 01: https://www.youtube.com/watch?v=sSno9rV8Rhg
/// resource 01: https://www.geeksforgeeks.org/printing-longest-common-subsequence/
/// time complexity O(length1 * length2).

#include<bits/stdc++.h>
#define mxlength 101
using namespace std;
int dp[mxlength][mxlength], t;
string s1, s2, output[mxlength][mxlength];

int LCS(int ln1, int ln2)
{
	for (int i = 0; i <= ln1; i++)
	{
		for (int j = 0; j <= ln2; j++)
		{
			if (i == 0 || j == 0)
				dp[i][j] = 0;

			else if (s1[i - 1] == s2[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];

			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[ln1][ln2];
}

string reverse(string s)
{
	int f = 0, e = s.size()-1;
	while (f <= e)
	{
		swap(s[f], s[e]);
		f++;
		e--;
	}
	return s;
}

string str = "";
void find_LCS(int i, int j)  /// this function will take too much time as it prints all possible LCS.
{
	if (i == 0 || j == 0)
	{
		str = reverse(str);
		cout << str << " ";
		return;
	}

	if (s1[i - 1] == s2[j - 1])
	{
		str.push_back(s1[i-1]);
		find_LCS(i - 1, j - 1);
		str.pop_back();
	}
	else
	{
		if (dp[i - 1][j] > dp[i][j - 1])
			find_LCS(i - 1, j);
		else if(dp[i - 1][j] < dp[i][j - 1])
			find_LCS(i, j-1);
		else
		{
			find_LCS(i - 1, j);
			find_LCS(i, j - 1);
		}
	}
}

int main()
{
	cout << "Enter the Strings :" << endl;
	cin >> s1 >> s2;
	int ln1 = s1.size();
	int ln2 = s2.size();
	cout << "LCS length is : " << LCS(ln1, ln2) << endl;
	cout << "The LCS are : ";
	find_LCS(ln1, ln2);
	return 0;
}