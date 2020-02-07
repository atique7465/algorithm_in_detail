#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll amount, no_of_coins,dp[501][501];

ll coin_change(ll i, ll make)
{
    if(i > no_of_coins)
        return make == 0;

    if(dp[i][make] != -1)
        return dp[i][make];

    ll status1 = 0, status2 = 0;
    if(make - i >=0)
        status1 = coin_change(i+1, make - i);

    status2 = coin_change(i+1, make);

    return dp[i][make] = status1 + status2; ///for how many ways.
}


int main()
{
    scanf("%lld",&amount);

    no_of_coins = amount - 1;

    memset(dp,-1,sizeof(dp));

    printf("%lld",coin_change(1,amount));

    return 0;
}
