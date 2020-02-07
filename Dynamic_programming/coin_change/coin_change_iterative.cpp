/// solution of lightoj 1231 coin change (II).
/// idea is number of ways the amount already made + if we take ith coin then number of ways (amount - ith coin) made.

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int i,j,t,n,value,limit;
int coin[110];
int dp[10001];

int coin_change()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=value; j++)
        {
            if(coin[i]<=j)
                dp[j]=(dp[j]+dp[j-coin[i]])%100000007;
        }
    }
    return dp[value];
}

int main()
{
    scanf("%d",&t);
    int cas=1;
    while(cas<=t)
    {
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        scanf("%d %d",&n,&value);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&coin[i]);
        }
        printf("Case %d: %d\n",cas,coin_change());
        cas++;
    }
    return 0;
}
