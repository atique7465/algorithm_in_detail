/// resource 01: http://www.shafaetsplanet.com/?p=1158
/// a list of coins, their limit and a amount are given. have to find out this amount can be made or not.
/// or, if possible then how many ways.
/// time complexity O(no_of_coins * highest_quantity * amount).
/// also known as subset sum problem by just considering each value once like 0_1_knapsack.

#include<bits/stdc++.h>
using namespace std;
int coins[101], limit[101], amount, no_of_coins,dp[11][16][1001],dir[11][16][1001];; /// highest 11 coins, excessed 15 times highest and highest amount is 1000

int coin_change(int i, int lm, int make)
{
    if(i > no_of_coins)
        return make == 0;

    if(dp[i][lm][make] != -1)
        return dp[i][lm][make];

    int status1 = 0, status2 = 0;
    if(lm < limit[i] && make - coins[i] >=0)
        status1 = coin_change(i, lm+1, make - coins[i]);

    status2 = coin_change(i+1, 0, make);

    if(status1 == 1)   /// for path finding
        dir[i][lm][make] = 1;
    else
        dir[i][lm][make] = 2;

    return dp[i][lm][make] = status1 | status2;
    //return dp[i][lm][make] = status1 + status2; ///for how many ways.
}

void selected_coins(int i, int lm, int make)
{   /// it prints one of the ways.
    if(dir[i][lm][make] == -1)
        return;

    if(dir[i][lm][make] == 1)
    {
        cout<<coins[i]<<" ";
        selected_coins(i, lm+1, make-coins[i]);
    }
    else
        selected_coins(i+1, 0, make);
}

int main()
{
    cout<<"Number of coins : ";
    cin>>no_of_coins;
    cout<<"enter the coins with value limit pair: "<<endl;
    for(int i = 1; i<=no_of_coins; i++)
        cin>>coins[i]>>limit[i];

    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dp));

    while(1)
    {
        cout<<"Check an amount : ";
        cin>>amount;
        if(coin_change(1,0,amount))
        {
            cout<<"Possible"<<endl;
            cout<<"selected coins are : ";
            selected_coins(1, 0, amount);
        }
        else
            cout<<"Not Possible!";

        cout<<endl;
    }

    return 0;
}

/*
INPUT:
Number of coins : 3
enter the coins with value limit pair:
1 5
2 5
5 5
Check an amount : 5
Possible
selected coins are : 1 1 1 1 1
Check an amount : 13
Possible
selected coins are : 1 1 1 1 1 2 2 2 2
Check an amount : 14
Possible
selected coins are : 1 1 1 1 1 2 2 5
Check an amount : 17
Possible
selected coins are : 1 1 1 1 1 2 5 5
Check an amount : 68
Not Possible!
Check an amount : 50
Not Possible!
Check an amount : 40
Possible
selected coins are : 1 1 1 1 1 2 2 2 2 2 5 5 5 5 5
Check an amount : 41
Not Possible!
*/

