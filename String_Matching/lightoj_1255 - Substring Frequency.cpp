#include<bits/stdc++.h>
#define mx 1000010
using namespace std;
int failure[mx];

void find_failor(string pattern)
{
	int m = pattern.size();
	failure[0] = failure[1] = 0;

	for (int i = 2; i <= m; i++)
	{
		int j = failure[i - 1];  /// as string indexing starts from 0 so, j in place of j+1 and i-1 for i.
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

int KMP(string text, string pattern)
{
	int n = text.size();
	int m = pattern.size();

	int cnt = 0;
	find_failor(pattern);

	int i = 0, j = 0;
	while (i < n)
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			if (j == m)
			{
				cnt++;
				j = failure[j-1];
				if (text[i-1] == pattern[j] && m>1)
					i = i - 1;
			}
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = failure[j];
		}
	}
	return cnt;
}

int main()
{
	string text, pattern;
	int cas = 1, t;
	scanf("%d", &t);
	while (cas <= t)
	{
		cin >> text >> pattern;
		int cnt = KMP(text, pattern);
		printf("Case %d: %d\n", cas, cnt);
		cas++;
	}
	return 0;
}