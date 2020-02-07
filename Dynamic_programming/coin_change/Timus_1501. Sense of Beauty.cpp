/// solve it later

#include<bits/stdc++.h>
using namespace std;
int n,dp[3][1001][2001],sz[3],ps[3],mnt[3];
string s[3];

int num_of_ways(int i, int pos, int tot)
{
    cout<<i<<" "<<pos<<" "<<tot<<endl;

    if(tot == 0)
        return 1;

    if(dp[i][pos][tot] != -1)
        return dp[i][pos][tot];

    int ret1 = 0, ret2 = 0;

    if(pos<n)
    {
        int k = s[i][pos] - '0';
        if(abs((sz[k]+1) - sz[(k+1)%2])<=1 && tot - 1 >=0)
        {
            sz[k]++;
            ps[i]++;
            mnt[i] = tot -1;
            ret1 = num_of_ways(i, pos+1, tot-1);
            sz[k]--;
            ps[i]--;
            mnt[i] = tot;
        }
    }

    if(mnt[(i+1)%2]>tot)
    {
        int tmp = mnt[(i+1)%2];
        ret2 = num_of_ways( (i+1) %2, ps[(i+1) %2], tot);
        mnt[(i+1)%2] = tmp;
    }

    return dp[i][pos][tot] = ret1+ret2;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);

    cin>>s[0]>>s[1];

    sz[0] = 0;
    sz[1] = 0;
    ps[0] = 0;
    ps[1] = 0;
    mnt[0] = 2*n;
    mnt[1] = 2*n;

    int res1 = 0;//num_of_ways(0,0,2*n);
    int res2 = num_of_ways(1,0,2*n);

    cout<<res1<<" "<<res2<<endl;

    //if(res1 || res1)
      //  cout<<"possible";
    //else
      //  printf("Impossible");

    return 0;
}

