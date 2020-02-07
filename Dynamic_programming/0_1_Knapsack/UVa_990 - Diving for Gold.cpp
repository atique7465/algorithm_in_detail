#include<bits/stdc++.h>
using namespace std;
int t,w,no_of_item,sack_size,prof[31],weight[31],i,dp[31][1001],dir[31][1001];
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
        dir[i][cap] = 1;
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
        return 1+selected_items(i+1,cap-weight[i]);
    }
    else
        return selected_items(i+1,cap);
}

int main()
{
    int ck = 0;
    while(scanf("%d %d",&t,&w)!=EOF)
    {
        if(ck == 1)
            printf("\n");
        ck = 1;

        sack_size = t;
        scanf("%d",&no_of_item);

        for(int i = 1; i<=no_of_item; i++){
            scanf("%d %d",&weight[i],&prof[i]);
            weight[i] = 3*w*weight[i];
        }

        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));

        printf("%d\n",knapsack_0_1(1,sack_size));

        cout<<selected_items(1,sack_size)<<endl;

        for(int i=0; i<selected.size(); i++)
            printf("%d %d\n",weight[selected[i]]/(3*w),prof[selected[i]]);
        selected.clear();
    }
    return 0;
}

