#include<bits/stdc++.h>
using namespace std;
int dp[(1 << 20) + 2], balcony[21], n;

int Set(int x, int pos) { return x = x | (1 << pos); }
int ReSet(int x, int pos) { return x = x & (~(1 << pos)); }
bool check(int x, int pos) { return x & (1 << pos); }

int Bitmask_dp(int mask)
{
	if (mask == 0)
		return 0;

	if (dp[mask] != -1)
		return dp[mask];

	int mn_damage = 1<<28;

	for (int i = 0; i < n; i++)
	{
		if (check(mask, i))
		{
			int new_mask = mask;
			new_mask = ReSet(new_mask, i);
			new_mask = ReSet(new_mask, (i+1)%n);
			new_mask = ReSet(new_mask, (i+2)%n);
			int damage = 0;
			for (int j = 0; j < n; j++)
			{
				if (i!=j && check(new_mask, j))
					damage += balcony[j];
			}
			mn_damage = min(mn_damage, damage + Bitmask_dp(new_mask));
		}
	}
	return dp[mask] = mn_damage;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &balcony[i]);

	printf("%d", Bitmask_dp(pow(2,n)-1));

	return 0;
}
