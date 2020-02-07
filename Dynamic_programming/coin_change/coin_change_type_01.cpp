/// resource 01: http://www.shafaetsplanet.com/?p=1158
/// a list of coins and a amount are given. have to find out this amount can be made or not.
/// or, if possible then how many ways.
/// time complexity O(no_of_coins * amount).
/// also known as subset sum problem by just considering each value once like 0_1_knapsack.

#include<bits/stdc++.h>
using namespace std;
int coins[101], amount, no_of_coins,dp[101][10000],dir[101][10000];

bool coin_change(int i, int make)
{
    if(i > no_of_coins)
        return make == 0;

    if(dp[i][make] != -1)
        return dp[i][make];

    int status1 = 0, status2 = 0;
    if(make - coins[i] >=0)
        status1 = coin_change(i, make - coins[i]);

    status2 = coin_change(i+1, make);

    if(status1 == 1)   /// for path finding
        dir[i][make] = 1;
    else
        dir[i][make] = 2;

    return dp[i][make] = status1 | status2;
    // return dp[i][make] = status1 + status2; ///for how many ways.
}

void selected_coins(int i, int make)
{   /// it prints one of the ways.
    if(dir[i][make] == -1)
        return;

    if(dir[i][make] == 1)
    {
        cout<<coins[i]<<" ";
        selected_coins(i, make-coins[i]);
    }
    else
        selected_coins(i+1, make);
}

int main()
{
    cout<<"Number of coins : ";
    cin>>no_of_coins;
    cout<<"enter the coins : ";
    for(int i = 1; i<=no_of_coins; i++)
        cin>>coins[i];

    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dp));

    while(1)
    {
        cout<<"Check an amount : ";
        cin>>amount;
        if(coin_change(1,amount))
        {
            cout<<"Possible"<<endl;
            cout<<"selected coins are : ";
            selected_coins(1,amount);
        }
        else
            cout<<"Not Possible!";

        cout<<endl;
    }

    return 0;
}

/*
INPUT:
Number of coins : 5
enter the coins : 5 8 11 15 18
Check an amount : 5
Possible
selected coins are : 5
Check an amount : 10
Possible
selected coins are : 5 5
Check an amount : 55
Possible
selected coins are : 5 5 5 5 5 5 5 5 5 5 5
Check an amount : 21
Possible
selected coins are : 5 5 11
Check an amount : 23
Possible
selected coins are : 5 5 5 8
Check an amount : 100
Possible
selected coins are : 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
Check an amount : 123
Possible
selected coins are : 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 8
Check an amount : 68
Possible
selected coins are : 5 5 5 5 5 5 5 5 5 5 5 5 8
Check an amount : 65
Possible
selected coins are : 5 5 5 5 5 5 5 5 5 5 5 5 5
Check an amount : 63
Possible
selected coins are : 5 5 5 5 5 5 5 5 5 5 5 8
Check an amount : 22
Possible
selected coins are : 11 11
*/
