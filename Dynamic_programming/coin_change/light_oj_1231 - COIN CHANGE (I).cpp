#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int i,t,n,value;
int coin[100],limit[100];
int dp[51][1001][21];

int coin_change(int i,int lim,int amount)
{
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }

    if(dp[i][amount][lim]!=-1)
    {
        return dp[i][amount][lim];
    }
    int a=0,b=0;
    if(lim<limit[i])
    {
        if(amount-coin[i]>=0)
            a=coin_change(i,lim+1,amount-coin[i])%100000007;
    }
    b=coin_change(i+1,0,amount)%100000007;

    return dp[i][amount][lim]=  (a + b)%100000007;
}

int main()
{
    scanf("%d",&t);
    int cas=1;
    while(cas<=t)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&value);
        for(i=0; i<n; i++)
        {
            scanf("%d",&coin[i]);
        }
        for(i=0; i<n; i++)
        {
            scanf("%d",&limit[i]);
        }
        printf("Case %d: %d\n",cas,coin_change(0,0,value)%100000007);
        cas++;
    }
    return 0;
}
