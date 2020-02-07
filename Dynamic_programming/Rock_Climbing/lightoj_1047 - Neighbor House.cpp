#include<bits/stdc++.h>
using namespace std;
int grid[21][4],dp[21][4],t,n;

int rock_climbing_fun(int i, int j)
{
    if( i>n ) /// if cell is out of grid.
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = INT_MAX;
    if(j==1)
    {
        ret = min(ret,rock_climbing_fun(i+1,2) + grid[i][j]);
        ret = min(ret,rock_climbing_fun(i+1,3) + grid[i][j]);
    }
    else if(j==2)
    {
        ret = min(ret,rock_climbing_fun(i+1,1) + grid[i][j]);
        ret = min(ret,rock_climbing_fun(i+1,3) + grid[i][j]);
    }

    else
    {
        ret = min(ret,rock_climbing_fun(i+1,1) + grid[i][j]);
        ret = min(ret,rock_climbing_fun(i+1,2) + grid[i][j]);
    }

    return dp[i][j] = ret;
}

int main()
{
    scanf("%d",&t);
    int cas = 1;
    while(cas <= t)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=3; j++)
               scanf("%d",&grid[i][j]);

        memset(dp,-1,sizeof(dp));

        int res = rock_climbing_fun(1,1);
        res = min(res,rock_climbing_fun(1,2));
        res = min(res,rock_climbing_fun(1,3));

        cout<<"Case "<<cas<<": "<<res<<endl;
        cas++;
    }

    return 0;
}
