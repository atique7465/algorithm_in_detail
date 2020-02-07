#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll coins[22], amount, no_of_coins,dp[22][10001];

ll coin_change(ll i, ll make)
{
    if(i > no_of_coins)
        return make == 0;

    if(dp[i][make] != -1)
        return dp[i][make];

    ll status1 = 0, status2 = 0;
    if(make - coins[i] >=0)
        status1 = coin_change(i, make - coins[i]);

    status2 = coin_change(i+1, make);

    return dp[i][make] = status1 + status2;
}

int main()
{
    no_of_coins = 21;
    for(ll i = 1; i<=21; i++)
        coins[i] = i*i*i;

    memset(dp,-1,sizeof(dp));

    while(cin>>amount)
    {
        cout<<coin_change(1,amount)<<endl;
    }
    return 0;
}
