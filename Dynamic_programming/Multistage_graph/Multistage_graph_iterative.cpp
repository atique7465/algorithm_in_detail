/// resource 01: https://www.youtube.com/watch?v=9iE9Mj4m8jk&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=47
/// resource 02: https://www.youtube.com/watch?v=FcScLYJI42E&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=48

#include<bits/stdc++.h>
using namespace std;
int edges[101][101],n,u,v,w,stage,e;

void find_min_cost_and_path()
{
    int cost[n+1];
    int dest[n+1];
    memset(cost,-1,sizeof(cost));
    cost[n] = 0;
    dest[n] = n;
    for(int i = n -1; i>=1; i--)
    {
        int min = INT_MAX;
        for(int j = 1; j<=n; j++)
        {
            if(edges[i][j]!=-1 && edges[i][j]+cost[j]<min)
            {
                min =  edges[i][j]+cost[j];
                dest[i] = j;
            }
        }
        cost[i] = min;
    }
    cout<<"Minimum Cost is : "<<cost[1]<<endl;
    cout<<"Path : ";
    int i = 1;
    while(1)
    {
        cout<<i<<" ";
        i = dest[i];
        if(i == n)
        {
            cout<<n;
            break;
        }
    }
}

int main()
{
    cout<<"Number of Nodes : ";
    cin>>n;
    cout<<"Enter no. of edges :";
    cin>>e;
    cout<<"Enter the edges : "<<endl;

    memset(edges,-1,sizeof(edges));
    for(int i = 1; i<=e; i++)
    {
        cin>>u>>v>>w;
        edges[u][v]=w;
    }

    cout<<"No. of stages : ";
    cin>>stage;

    find_min_cost_and_path();

    return 0;
}

/*
INPUT:
12
21
1 2 9
1 3 7
1 4 3
1 5 2
2 6 4
2 7 2
2 8 1
3 6 2
3 7 7
4 8 11
5 7 11
5 8 8
6 9 6
6 10 5
7 9 4
7 10 3
8 10 5
8 11 6
9 12 4
10 12 2
11 12 5
4
OUTPUT:
Minimum Cost is : 16
Path : 1 2 7 10 12
*/
