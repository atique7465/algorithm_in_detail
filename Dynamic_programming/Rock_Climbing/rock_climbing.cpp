/// resource: http://www.shafaetsplanet.com/?p=1158

#include<bits/stdc++.h>
using namespace std;
int grid[101][101],r,c,dp[101][101],inf = INT_MIN;

int rock_climbing_fun(int i, int j)
{
    if( i<1 || i>r || j<1 || j>c) /// if cell is out of grid.
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ret = inf;
    ret = max(ret, rock_climbing_fun(i+1,j) + grid[i][j]);
    ret = max(ret, rock_climbing_fun(i+1,j-1) + grid[i][j]);
    ret = max(ret, rock_climbing_fun(i+1,j+1) + grid[i][j]);

    return dp[i][j] = ret;
}

int main()
{
    cout<<"Row of grid : ";
    cin>>r;
    cout<<"Column of grid : ";
    cin>>c;
    cout<<"Enter the matrix : "<<endl;
    for(int i = 1; i<=r; i++)
        for(int j = 1; j<=c; j++)
            cin>>grid[i][j];

    memset(dp,-1,sizeof(dp));
    cout<<"Maximum value : "<<rock_climbing_fun(1,1);

    return 0;
}

/*
INPUT:
Row of grid : 3
Column of grid : 3
Enter the matrix :
-1 2 5
4 -2 3
1 2 10
Maximum value : 7
*/
