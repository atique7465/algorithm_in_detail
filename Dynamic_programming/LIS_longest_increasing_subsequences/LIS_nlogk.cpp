/// resource 01: http://www.lightoj.com/article_show.php?article=1000
/// time complexity O(n log k). where n is number of items k is LIS length
/// for Longest Decreasing Subsequence or LDS just reverse the sequence and use the method for LIS
#include<bits/stdc++.h>
using namespace std;
int arr[101],L[101],n, inf = INT_MAX;
vector<int>s;

int LIS()
{
    int I[n+1];
    I[0] = -inf;
    for(int i = 1; i<=n; i++)
        I[i] = inf;

    int length = 0;

    for(int i=1; i<=n; i++)
    {
        int low = 0, high = length,mid;
        while(low <= high)
        {
            mid = (low+high)/2;
            if(I[mid] < arr[i])
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = arr[i];
        if(length <= low)
            length = low;
        L[i] = length;
    }
    return length;
}

void LS(int mxl)
{
    int i;
    for(i=1; i<=n; i++)
        if(L[i]==mxl)
            break;

    int v = arr[i];
    mxl--;
    s.push_back(v);
    for(int j=i-1; j>=1; j--)
        if(arr[j]<v && L[j]==mxl)
        {
            v = arr[j];
            s.push_back(v);
            mxl--;
        }
}

int main()
{
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    int mxl = LIS();
    cout<<"Longest Increasing Subsequence is : "<<mxl<<endl;
    if(mxl)
    {
        cout<<"Longest Subsequence : ";
        LS(mxl);
        for(int i=s.size()-1; i>=0; i--)
            cout<<s[i]<<" ";
    }

    return 0;
}

/*
Enter the number of elements : 10
Enter the elements : 8 1 9 8 3 4 6 1 5 2
Longest Increasing Subsequence is : 4
Longest Subsequence : 1 3 4 6
*/

