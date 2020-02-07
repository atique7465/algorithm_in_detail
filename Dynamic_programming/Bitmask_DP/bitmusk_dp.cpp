/// problem statement & resource : http://www.shafaetsplanet.com/?p=1357
/// use when n<16;
/// it will be applicable when to calculate present state we need to know the status of node/items/digit of previous states.
/// time complexity O( 2^n * n^2 )

#include<bits/stdc++.h>
using namespace std;
int price[21][21], n, dp[(1 << 15) + 2];

int Set(int x, int pos){return x = x | (1 << pos);}
int reset(int x, int pos){return x = x & (~(1 << pos));}
bool check(int x, int pos){return x & (1 << pos);}

int Bitmask_dp(int mask)
{
    if (mask == (1 << n) - 1)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    int minimum = 1 << 28;
    for (int i = 0; i < n; i++)
    {
        if (check(mask, i) == 0)
        {
            int cost = price[i][i];
            for (int j = 0; j < n; j++)
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
    memset(dp, -1, sizeof(dp));

    cout << "No of items : ";
    cin >> n;
    cout << "Enter the price matrix :" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> price[i][j];


    cout << Bitmask_dp(0);

    return 0;
}
