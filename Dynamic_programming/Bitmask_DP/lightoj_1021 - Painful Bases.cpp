#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[(1 << 16) + 2][21], digits[16], base,n,k;
string s;

ll Set(ll x, ll pos) { return x = x | (1 << pos); }
ll ReSet(ll x, ll pos) { return x = x & (~(1 << pos)); }
bool check(ll x, ll pos) { return x & (1 << pos); }

ll Bitmask_dp(ll mask, ll rem)
{
	if (mask == (1 << n) - 1)
	{
		if (rem == 0)
			return 1;
		else
			return 0;
	}

	if (dp[mask][rem] != -1)
		return dp[mask][rem];

	ll res = 0;

	for (ll i = 0; i < n; i++)
	{
		if (!check(mask, i))
		{
			res += Bitmask_dp(Set(mask, i), (rem * base + digits[i]) % k);
		}
	}
	return dp[mask][rem] = res;
}

int main()
{
	ll cas = 1,t;
	scanf("%lld", &t);

	while (cas <= t)
	{
		memset(dp, -1, sizeof(dp));
		scanf("%lld %lld", &base,&k);

		cin >> s;
		n = s.size();

		for (ll i = 0; i < n; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
				digits[i] = s[i] - '0';
			else
				digits[i] = s[i] - 'A' + 10;
		}

		printf("Case %lld: %lld\n", cas, Bitmask_dp(0,0));
		cas++;
	}

	return 0;
}
