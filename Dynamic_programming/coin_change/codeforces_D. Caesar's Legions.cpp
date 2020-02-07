/*
idea:
just took 4 step dp as id , n limit, k limit, total = n1+n2;
and run like coin change dp.
*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll m = 100000000,n[3],k[3],ns[3],dp[3][101][11][201];

ll num_of_ways(int i, int lm, int alm, int tot)
{
    if(tot == 0)
        return 1;

    if(dp[i][lm][alm][tot] != -1)
        return dp[i][lm][alm][tot];

    int ret1 = 0, ret2 = 0;

    if(lm<n[i] && alm<k[i] && tot - 1 >=0)
    {
        ns[i] = lm+1;    /// as current item took for another time.
        ret1 = num_of_ways(i, lm+1, alm+1, tot-1);
        ns[i]--;        /// to maintain consistency.
    }
    if(alm>0)  /// wont call another option if didn't take at least one of current item
        ret2 = num_of_ways( (i+1) %2, ns[(i+1) %2], 0, tot); /// if able to call another item then call it with its current ns status;

    return dp[i][lm][alm][tot] = (ret1 + ret2) % m;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld %lld %lld %lld",&n[0],&n[1],&k[0],&k[1]);

    ns[0] = 0, ns[1] = 0;
    ll res = num_of_ways(0,1,++ns[0],n[0]+n[1]-1);   /// n1+n2-1 as i considered the taken one time already
    ns[0]=0;
    res = ( res + num_of_ways(1,1,++ns[1],n[0]+n[1]-1) ) % m;

    printf("%lld",res);

    return 0;
}
