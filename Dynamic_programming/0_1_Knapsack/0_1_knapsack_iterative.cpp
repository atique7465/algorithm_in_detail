/// resource 01: https://www.youtube.com/watch?v=zRza99HPvkQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=55
/// resource 02: http://www.shafaetsplanet.com/planetcoding/?p=1072
/// just take the profit as maximum profit between taking current item and without taking current item.
/// time complexity O(no_of_item * sack_size) or O(n*w)

#include<bits/stdc++.h>
using namespace std;
int no_of_item,p,w,sack_size,prof[101],weight[101],i,dp[101][101];

int knapsack_0_1()
{
    for(i = 0; i<=no_of_item; i++)
    {
        for(w = 0; w<=sack_size; w++)
        {
           if(i == 0 || w == 0)
            dp[i][w] = 0;

           else if(weight[i] <= w)
            dp[i][w] = max(prof[i]+dp[i-1][w-weight[i]] , dp[i-1][w]);

           else
            dp[i][w] = dp[i-1][w];
        }
    }
    return dp[no_of_item][sack_size];
}

void selected_items()
{
    int i = no_of_item;
    int j = sack_size;
    while(i>0 && j>0)
    {
        if(dp[i][j] != dp[i-1][j])
        {
            cout<<i<<" ";
            j = j - weight[i];
            i--;
        }
        else
            i--;
    }
}

int main()
{
    cout<<"Enter the sack size: ";
    cin>>sack_size;
    cout<<"Enter the number of items: ";
    cin>>no_of_item;

    cout<<"Enter the items with profit weight pair : "<<endl;
    for(int i = 1; i<=no_of_item; i++)
    {
        cin>>prof[i]>>weight[i];
    }

    cout<<"Max Profit : "<<knapsack_0_1()<<endl;
    cout<<"The items taken are : ";
    selected_items();

    return 0;
}

/*
INPUT 01:
Enter the sack size: 15
Enter the number of items: 7
Enter the items with profit weight pair :
10 5
5 3
15 5
7 7
6 1
18 4
3 1
Max Profit : 49
The items taken are : 6 5 3 1

INPUT 02:
Enter the sack size: 8
Enter the number of items: 4
Enter the items with profit weight pair :
1 2
2 3
5 4
6 5
Max Profit : 8
The items taken are : 4 2

INPUT: 03
Enter the sack size: 10
Enter the number of items: 5
Enter the items with profit weight pair :
120 1
400 7
280 4
150 3
200 4
Max Profit : 600
The items taken are : 5 3 1
*/


