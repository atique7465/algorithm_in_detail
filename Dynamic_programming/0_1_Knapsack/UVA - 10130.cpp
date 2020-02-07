#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll i,t,j,n,dp[1005][35],a,b,g,mw,sum;
int cost[1001],weight[1001];

ll func(ll i, ll cap)
{
    if(i == n+1)
        return 0;

    if(dp[i][cap] != -1)
        return dp[i][cap];

    int prof1 = 0,prof2 = 0;
    if(cap - weight[i] >= 0)
        prof1=cost[i]+func(i+1,cap - weight[i]);

    prof2=func(i+1,cap);

    return dp[i][cap]=max(prof1,prof2);;
}

int main()
{
    scanf("%lld",&t);
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        sum=0;
        scanf("%lld",&n);
        for(i=1; i<=n; i++)
            scanf("%lld %lld",&cost[i],&weight[i]);

        scanf("%lld",&g);
        for(i=1; i<=g; i++)
        {
            scanf("%lld",&mw);
            sum += func(1,mw);
        }
        printf("%lld\n",sum);
    }
    return 0;
}
