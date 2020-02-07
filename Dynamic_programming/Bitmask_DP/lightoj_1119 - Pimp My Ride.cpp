#include<bits/stdc++.h>
using namespace std;
int price[14][14], no_of_jobs, dp[(1 << 14) + 2];

int Set(int x, int pos){return x = x | (1 << pos);}
int reset(int x, int pos){return x = x & (~(1 << pos));}
bool check(int x, int pos){return x & (1 << pos);}

int Bitmask_dp(int mask)
{
    if (mask == (1 << no_of_jobs) - 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int minimum = 1 << 28;
    for (int i = 0; i < no_of_jobs; i++)
    {
        if (check(mask, i) == 0)
        {
            int cost = price[i][i];
            for (int j = 0; j < no_of_jobs; j++)
            {
                if (i != j && check(mask, j) != 0)
                {
                    cost += price[i][j];
                }
            }
            minimum = min(minimum, cost + Bitmask_dp(Set(mask, i)));
        }
    }
    return dp[mask] = minimum;
}

int main()
{
    int t,cas = 1;
    scanf("%d", &t);

    while(cas<=t)
    {
        memset(dp, -1, sizeof(dp));

        scanf("%d",&no_of_jobs);
       
        for (int i = 0; i < no_of_jobs; i++)
            for (int j = 0; j < no_of_jobs; j++)
                scanf("%d",&price[i][j]);

        printf("Case %d: %d\n",cas,Bitmask_dp(0));
        
        cas++;
    }

    return 0;
}
