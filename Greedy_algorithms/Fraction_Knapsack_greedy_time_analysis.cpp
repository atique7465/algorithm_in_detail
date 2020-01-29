/// choosing the items with as high value-to-weight ratios as possible.
/// Sorting by any advanced algorithm is O(N log N)
/// resource: https://www.youtube.com/watch?v=oTTzNMHM05I&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=40

#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define max_number_of_items 150000

struct item
{
    int item_profit, item_weight;
    item(int p = 0, int w = 0)
    {
        item_profit = p;
        item_weight = w;
    }

    bool operator < (item &ob)const
    {
        double r1 = (double)item_profit / item_weight;
        double r2 = (double)ob.item_profit / ob.item_weight;
        return r1 > r2;
    }
};

double greedy_knapsack(item item_list[], int number_of_items, int knapsack_size)
{
    sort(item_list, item_list + number_of_items); /// main time complexity here (n log n)

    int current_weight = 0;
    double max_profit = 0.0;

    for(int i = 0; i<number_of_items; i++)
    {
        if(current_weight + item_list[i].item_weight <= knapsack_size)
        {
            current_weight += item_list[i].item_weight;
            max_profit += item_list[i].item_profit;
        }
        else
        {
            int remain = knapsack_size - current_weight;
            max_profit += item_list[i].item_profit * ((double) remain / item_list[i].item_weight);
            break;
        }
    }
    return max_profit;
}

int main()
{
    int knapsack_size, number_of_items, p, w;
    item item_list[max_number_of_items];

    cout<<"Enter the knapsack size : ";
    cin>>knapsack_size;

    cout<<"Enter the number of items : ";
    cin>>number_of_items;

    freopen("dataset_ex_1.txt","r",stdin);
    for(int i = 0; i < number_of_items; i++)
    {
        cin>>p>>w;
        item ob(p, w);
        item_list[i] = ob;
    }

    auto start = chrono::high_resolution_clock::now(); /// Get starting timepoint
    double res = greedy_knapsack(item_list, number_of_items, knapsack_size);
    auto stop = chrono::high_resolution_clock::now();  /// Get ending timepoint

    cout<<"MaximumPossible profit is :"<<res<<endl;

    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed  << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;
}

