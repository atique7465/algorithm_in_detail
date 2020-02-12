/*
idea : just check the match of highest prefix of Reverse(input) in input string. 
then result is: 2 * n - match_position
*/


#include<bits/stdc++.h>
#define mx 1000010
using namespace std;
int failure[mx], cas = 1, t, n, m;
string text, pattern;

string Reverse(string s)
{
	int f = 0, e = s.size() - 1;
	while (f <= e)
	{
		swap(s[f], s[e]);
		f++;
		e--;
	}
	return s;
}

void find_failor()
{
	failure[0] = failure[1] = 0;

	for (int i = 2; i <= m; i++)
	{
		int j = failure[i - 1];
		while (1)
		{
			if (pattern[j] == pattern[i - 1])
			{
				failure[i] = j + 1;
				break;
			}

			if (j == 0)
			{
				failure[i] = 0;
				break;
			}

			j = failure[j];
		}
	}
}

int KMP()
{
	int i = 0, j = 0;
	while (i < n)
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			if (j == m)
				break;
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = failure[j];
		}
	}
	return j;
}

int main()
{
	cin >> t;
	while (cas <= t)
	{
		cin >> text;
		n = m = text.size();
        pattern = Reverse(text);

		find_failor();

		int highest_match = KMP();

		printf("Case %d: %d\n", cas, 2 * n - highest_match);
		cas++;
	}
	return 0;
}