/// choosing all subset of items and check whether it provides maximum profit or not.
/// To choose all subset time complexity is O( 2^n )

#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define max_number_of_items 150000

int bruteforce(int profit[], int weight[], int number_of_items, int knapsack_size)
{
    int max_profit = 0;
    int choice[number_of_items];
    memset(choice,0,sizeof(choice));

    for (int i=0; ; i++)
    {
        int j = number_of_items;
        int tempWeight = 0;
        int tempValue = 0;
        int k;
        k = 1;
        for (j = 0; j < number_of_items; j++)
        {
            choice[j] += k;
            k = choice[j] / 2;
            choice[j] = choice[j] % 2;
        }
        if (k)
            break;
        for (k = 0; k < number_of_items; k++)
        {
            if (choice[k] == 1)
            {
                tempWeight = tempWeight + weight[k];
                tempValue = tempValue + profit[k];
            }
        }
        if (tempValue > max_profit && tempWeight <= knapsack_size)
        {
            max_profit = tempValue;
        }
    }
    return max_profit;
}

int main()
{
    int knapsack_size,number_of_items;
    int profit[max_number_of_items];
    int weight[max_number_of_items];

    cout<<"Enter the knapsack size : ";
    cin>>knapsack_size;

    cout<<"Enter the number of items : ";
    cin>>number_of_items;

    freopen("dataset_ex_1.txt","r",stdin);
    for(int i = 0; i < number_of_items; i++)
        cin>>profit[i]>>weight[i];

    auto start = chrono::high_resolution_clock::now();/// Get starting timepoint
    int res = bruteforce(profit, weight, number_of_items, knapsack_size);
    auto stop = chrono::high_resolution_clock::now();/// Get ending timepoint

    cout<<"MaximumPossible profit is :"<<res<<endl;

    double time_taken =  chrono::duration_cast<chrono::nanoseconds>(stop - start).count();
    time_taken *= 1e-9;
    cout << "Time taken by program is : " << fixed  << time_taken << setprecision(9);
    cout << " sec" << endl;

    return 0;
}
