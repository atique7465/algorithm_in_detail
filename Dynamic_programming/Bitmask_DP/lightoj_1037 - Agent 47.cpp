#include<bits/stdc++.h>
using namespace std;
int dp[(1 << 15) + 2], welth[16], n;
string sord[16];

int Set(int x, int pos) { return x = x | (1 << pos); }
int ReSet(int x, int pos) { return x = x & (~(1 << pos)); }
bool check(int x, int pos) { return x & (1 << pos); }

int Bitmask_dp(int mask)
{
	if (mask == 0)
		return 0;

	if (dp[mask] != -1)
		return dp[mask];

	int mn_shot = 1<<28;

	for (int i = 0; i < n; i++)
	{
		if (check(mask, i))
		{
			int power = 1;
			for (int j = 0; j < n; j++)
			{
				if (i!=j && !check(mask, j))
					power = max(power,sord[j][i]-'0');
			}
			int need = welth[i] / power;
			if (welth[i] % power > 0)
				need++;

			mn_shot = min(mn_shot, need + Bitmask_dp(ReSet(mask, i)));
		}
	}
	return dp[mask] = mn_shot;
}

int main()
{
	int cas = 1,t;
	scanf("%d", &t);

	while (cas <= t)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%d", &n);

		for (int i = 0; i < n; i++)
			scanf("%d", &welth[i]);

		for (int i = 0; i < n; i++)
			cin >> sord[i];

		printf("Case %d: %d\n", cas, Bitmask_dp(pow(2, n) - 1));
		cas++;
	}

	return 0;
}
