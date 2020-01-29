/// choosing the items with as high value-to-weight ratios as possible.
/// Sorting by any advanced algorithm is O(N log N)

#include<bits/stdc++.h>
using namespace std;
int n,p,w,sack_size;

struct item
{
    int profit,weight;
    item(int p = 0, int w = 0)
    {
        profit = p;
        weight = w;
    }
    bool operator < (item &ob)const
    {
        double r1 = (double)profit / weight;
        double r2 = (double)ob.profit / ob.weight;
        return r1 > r2; /// as i want descending order sorted list
    }
};

double max_profit(item item_list[])
{
    double mx_profit = 0.0;
    int curr_sack_size = 0;
    sort(item_list,item_list + n);
    for(int i = 0; i<n; i++)
    {
        if(curr_sack_size + item_list[i].weight <= sack_size)
        {
            mx_profit += (double)item_list[i].profit;
            curr_sack_size += item_list[i].weight;
        }
        else
        {
            double r = (double)item_list[i].profit / item_list[i].weight;
            mx_profit += r * (sack_size - curr_sack_size);
            break;
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
    for(int i = 0; i<n; i++)
    {
        cin>>p>>w;
        item ob(p,w);
        item_list[i] = ob;
    }

    cout<<"Max Profit : "<<max_profit(item_list)<<endl;

    return 0;
}

/*
15
7
10 5
5 3
15 5
7 7
6 1
18 4
3 1
result: 50
*/


