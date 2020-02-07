/// fibonacci recursion with memoization [ O(n) ]
/// resource : http://www.shafaetsplanet.com/planetcoding/?p=1022

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

