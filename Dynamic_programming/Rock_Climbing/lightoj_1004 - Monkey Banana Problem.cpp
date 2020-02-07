#include<bits/stdc++.h>
using namespace std;
int grid[201][101],r,c,dp[201][101],t,n;

int rock_climbing_fun(int i, int j)
{
    if( i>n && (i>2*n-1 || j<1 ||  j>2*n-i)) /// if cell is out of grid.
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = -1;
    ret = max(ret,rock_climbing_fun(i+1,j) + grid[i][j]);

    if(i<n)
        ret = max(ret,rock_climbing_fun(i+1,j+1) + grid[i][j]);
    else
        ret = max(ret,rock_climbing_fun(i+1,j-1) + grid[i][j]);

    return dp[i][j] = ret;
}

int main()
{
    scanf("%d",&t);
    int cas = 1;
    while(cas <= t)
    {
        scanf("%d",&n);
        for(int i=1; i<=2*n-1; i++)
        {
            if(i<=n)
                for(int j=1; j<=i; j++)
                    scanf("%d",&grid[i][j]);

            else
                for(int j=1; j<=2*n-i; j++)
                    scanf("%d",&grid[i][j]);
        }

        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cas<<": "<<rock_climbing_fun(1,1)<<endl;
        cas++;
    }

    return 0;
}


