/// resource 01: http://www.shafaetsplanet.com/?p=1211
/// time complexity O(n^2).
/// for Longest Decreasing Subsequence or LDS just reverse the sequence and use the method for LIS

#include<bits/stdc++.h>
using namespace std;
int arr[101],dp[101],dir[101],n;
vector<int>s;

int LIS(int i)
{

    if(dp[i]!=-1)
        return dp[i];

    int mx = 0;
    for(int j = i+1; j<=n; j++)
    {
        if(arr[j]>arr[i])
        {
            int c = LIS(j);
            if(c>mx)
            {
                mx = c;
                dir[i] = j; /// for sequence path
            }
        }
    }
    return dp[i] = mx + 1;
}

void LS(int i)
{
    if(dir[i]==-1)
    {
        cout<<arr[i];
        return;
    }

    cout<<arr[i]<<" ";
    LS(dir[i]);
}

int main()
{
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    int mxl = INT_MIN,start;
    for(int i=1; i<=n; i++)
    {
        int c = LIS(i);
        if(c>mxl)
        {
            mxl = c;
            start = i;
        }
    }

    cout<<"Longest Increasing Subsequence length : "<<mxl<<endl;
    if(mxl>0)
    {
        cout<<"Longest Subsequence : ";
        LS(start);
    }

    return 0;
}

/*
Enter the number of elements : 10
Enter the elements : 8 1 9 8 3 4 6 1 5 2
Longest Increasing Subsequence length : 4
Longest Subsequence : 1 3 4 6
*/

