/// resource 01: https://www.youtube.com/watch?v=zRza99HPvkQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=55
/// resource 02: http://www.shafaetsplanet.com/planetcoding/?p=1072
/// just take the profit as maximum profit between taking current item and without taking current item.
/// time complexity O(no_of_item * sack_size) or O(n*w)

#include<bits/stdc++.h>
using namespace std;
int no_of_item,p,w,sack_size,prof[101],weight[101],i,dp[101][101],dir[101][101];
vector<int>selected;

int knapsack_0_1(int i, int cap)
{
    if(i > no_of_item || cap == 0)
        return 0;

    if(dp[i][cap] != -1)
        return dp[i][cap];

    int p1 = 0, p2 = 0;

    if(cap - weight[i] >=0)
        p1 = prof[i] + knapsack_0_1(i+1, cap - weight[i]);

    p2 = knapsack_0_1(i+1, cap);

    if(p1>p2)
        dir[i][cap] = 1;  /// for path finding
    else
        dir[i][cap] = 2;

    return dp[i][cap] = max(p1,p2);
}

int selected_items(int i, int cap)
{
    if(dir[i][cap] == -1)
        return 0;

    if(dir[i][cap] == 1)
    {
        selected.push_back(i);
        return 1 + selected_items(i+1,cap-weight[i]);  /// 1 added to find how many have selected.
    }
    else
        return selected_items(i+1,cap);
}

int main()
{
    cout<<"Enter the sack size: ";
    cin>>sack_size;
    cout<<"Enter the number of items: ";
    cin>>no_of_item;

    cout<<"Enter the items with profit weight pair : "<<endl;
    for(int i = 1; i<=no_of_item; i++)
        cin>>prof[i]>>weight[i];


    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));

    cout<<"Max Profit : "<<knapsack_0_1(1,sack_size)<<endl;
    cout<<"Number of items taken are : "<<selected_items(1,sack_size)<<endl;
    cout<<"They are : "<<endl;
    for(int i=0; i<selected.size(); i++)
        cout<<"Item : "<<selected[i]<<endl;

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
Number of items taken are : 4
They are :
Item : 1
Item : 3
Item : 5
Item : 6

INPUT 02:
Enter the sack size: 8
Enter the number of items: 4
Enter the items with profit weight pair :
1 2
2 3
5 4
6 5
Max Profit : 8
Number of items taken are : 2
They are :
Item : 2
Item : 4

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
Number of items taken are : 3
They are :
Item : 1
Item : 3
Item : 5
*/


