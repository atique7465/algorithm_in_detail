/// choosing all subset of items and check whether it provides maximum profit or not.
/// To choose all subset time complexity is O( 2^n )

#include<bits/stdc++.h>
using namespace std;
int n,p,w,sack_size;
vector<int>selected_items;

struct item
{
    int profit,weight;
    item(int p = 0, int w = 0)
    {
        profit = p;
        weight = w;
    }
};

int pow_fun(int a, int b)
{
    int ans = 1;
    while(b>0)
    {
        if(b%2==1)
            ans *= a;
        a *= a;
        b /= 2;
    }
    return ans;
}

int max_profit(item item_list[])
{
    int mx_profit = 0;
    int up = pow_fun(2,n);

    for(int i = 0; i<up; i++)
    {
        int prop = 0;
        int curr_sack_size = 0;
        int k = n;
        int v = i;
        vector<int>selected;
        while(v > 0)
        {
            if(v%2 == 1 && curr_sack_size + item_list[k].weight <= sack_size )
            {
                prop += item_list[k].profit;
                curr_sack_size += item_list[k].weight;
                selected.push_back(k);
            }
            else if(v%2 == 1 && curr_sack_size + item_list[k].weight > sack_size )
                break;
            k--;
            v /= 2;
        }
        if(prop > mx_profit)
        {
            mx_profit = prop;
            selected_items = selected;
        }
    }
    return mx_profit;
}

int main()
{
    cout<<"Enter the sack size: ";
    cin>>sack_size;
    cout<<"Enter the number of items: ";
    cin>>n;

    item item_list[n+1];
    cout<<"Enter the items with profit weight pair : "<<endl;
    for(int i=1; i<=n; i++)
    {
        cin>>p>>w;
        item ob(p,w);
        item_list[i] = ob;
    }

    cout<<"Max Profit : "<<max_profit(item_list)<<endl;
    cout<<"selected items : ";
    for(int i = selected_items.size()-1; i>=0; i--)
        cout<<selected_items[i]<<" ";

    return 0;
}

/*
7
10 5
5 3
15 5
7 7
6 1
18 4
3 1
15
result: 49
*/
