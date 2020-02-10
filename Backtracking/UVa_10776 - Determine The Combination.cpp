#include<bits/stdc++.h>
using namespace std;
int n, r;
string s, ans;

void combinations(int at, int remain)
{
	if (remain == 0)
	{
		cout << ans << endl;
		return;
	}

	for (int i = at; i <= n - remain; i++)
	{
		ans.push_back(s[i]);
		combinations(i + 1, remain - 1);
		ans.pop_back();
		while (s[i] == s[i + 1])   /// as we dont need to print duplicate combinations.
			i++;
	}
}

int main()
{
	while (cin >> s >> r)
	{
		sort(s.begin(), s.end());
		n = s.size();
		if (r > 0)
			combinations(0, r);
	}
	return 0;
}