/// resource 01: http://www.lightoj.com/article_show.php?article=1000
/// we can do it only by two loop as brute force. hare a tabular dp is implemented.
/// time complexity O(n^2).
/// for Longest Decreasing Subsequence or LDS just reverse the sequence and use the method for LIS

#include<bits/stdc++.h>
using namespace std;
int arr[101],L[101],n, mx = INT_MIN;
vector<int>s;

int LIS()
{
    for(int i=0; i<=n; i++)
        L[i] = 1;

    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++)
            if(arr[j]>arr[i] && L[j]<L[i]+1)
                L[j] = L[i]+1;

    for(int i=1; i<=n; i++)
        if(L[i]>mx)
            mx = L[i];

    return mx;
}

void LS()
{
    int i;
    for(i=1; i<=n; i++)
        if(L[i]==mx)
            break;

    int v = arr[i];
    mx--;
    s.push_back(v);
    for(int j=i-1; j>=1; j--)
        if(arr[j]<v && L[j]==mx)
        {
            v = arr[j];
            s.push_back(v);
            mx--;
        }
}

int main()
{
    cout<<"Enter the number of elements : ";
    cin>>n;
    cout<<"Enter the elements : ";
    for(int i=1; i<=n; i++)
        cin>>arr[i];

    cout<<"Longest Increasing Subsequence is : "<<LIS()<<endl;
    cout<<"Longest Subsequence : ";
    LS();
    for(int i=s.size()-1; i>=0; i--)
        cout<<s[i]<<" ";
    return 0;
}

/*
Enter the number of elements : 10
Enter the elements : 8 1 9 8 3 4 6 1 5 2
Longest Increasing Subsequence is : 4
Longest Subsequence : 1 3 4 6
*/
