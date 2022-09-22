/// Complexity:
/*  Recursion 
       - T --> O(n) for linear pattern
       - M --> O(n) + O(n) [1st for DP, 2nd for stack trace]
    Tabulation
       - T --> O(n) for linear pattern
       - M --> O(n) [No memory required for stack trace]
    Memory Optimization / Use variable for prev state
       - T --> O(n) for linear pattern
       - M --> O(1) [No extra memory required] */

/// resource : 0. https://www.youtube.com/watch?v=tyB0ztf0DNY&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=2&ab_channel=takeUforward
///            1. http://www.shafaetsplanet.com/planetcoding/?p=1022

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll arr[100000000];

ll fibo(ll n)
{
    if(n<2)
        return n;
    if(arr[n]!=0)
            return arr[n];
    arr[n]=fibo(n-1)+fibo(n-2);

    return arr[n];
}
int main()
{
    cout<<fibo(100)<<endl;
    return 0;
}

