#include<bits/stdc++.h>
using namespace std;
int dp[(1 << 12) + 2];
string s;

int Set(int x, int pos) { return x = x | (1 << pos); }
int ReSet(int x, int pos) { return x = x & (~(1 << pos)); }
bool check(int x, int pos) { return x & (1 << pos); }

int Bitmask_dp(int mask)
{
    if (dp[mask] != -1)
        return dp[mask];

    int mx = 0;

    for (int i = 0; i < 12-2; i++)
    {
        if (check(mask, i) && check(mask, i + 1) && !check(mask, i + 2))
        {
            int new_mask = mask;
            new_mask = ReSet(new_mask, i);
            new_mask = ReSet(new_mask, i+1);
            new_mask = Set(new_mask, i+2);
            mx = max(mx, 1 + Bitmask_dp(new_mask));
        }

        if (!check(mask, i) && check(mask, i + 1) && check(mask, i + 2))
        {
            int new_mask = mask;
            new_mask = Set(new_mask, i);
            new_mask = ReSet(new_mask, i + 1);
            new_mask = ReSet(new_mask, i + 2);
            mx = max(mx, 1 + Bitmask_dp(new_mask));
        }
    }
    return dp[mask] = mx;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        memset(dp, -1, sizeof(dp));

        cin >> s;
        int mask = 0, cnt = 0;

        for (int i = 0; i < 12; i++)
        {
            if (s[i] == 'o')
            {
                mask = Set(mask, i);
                cnt++;
            }
        }

        printf("%d\n",cnt - Bitmask_dp(mask));
    }

    return 0;
}
