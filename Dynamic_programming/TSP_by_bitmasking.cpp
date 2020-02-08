/// resource 01 : https://www.youtube.com/watch?v=Q4zHb-Swzro&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=58
/// resource 02 : https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
/// problem statement : Given a set of cities and distance between every pair of cities, the problem is to find 
///                     the shortest possible route that visits every city exactly once and returns to the starting point.
/// recurence relation : F(i,s) = min{ cost[i,k] + F(k, s-{k} ), here s is set of remaining nodes.
/// time complexity : O( 2^n * n^2 ). its an np hard problem.


#include<bits/stdc++.h>
#define mx 21
using namespace std;
int no_of_cities, edge[mx][mx], dp[mx][(1<<mx)+2], path[mx][(1 << mx) + 2];

int Set(int x, int pos) { return x = x | (1 << pos); }
int ReSet(int x, int pos) { return x = x & (~(1 << pos)); }
bool check(int x, int pos) { return x & (1 << pos); }

int TSP(int i, int mask)
{
	if (mask == (1<<no_of_cities) - 1)
		return edge[i][0];

	if (dp[i][mask] != -1)
		return dp[i][mask];
    
	int res = 1<<28;
	for (int j = 0 ; j < no_of_cities; j++)
	{
		if (!check(mask, j))
		{
			int c = TSP(j, Set(mask, j));
			if (edge[i][j] + c < res)
			{
				res = edge[i][j] + c;
				path[i][mask] = j; /// for printing the path later.
			}	
		}
	}
	return dp[i][mask] = res;
}

void print_path(int i, int mask)
{
	if (mask == (1 << no_of_cities) - 1)
	{
		cout << "1";
		return;
	}

	int j = path[i][mask];
	cout << j+1 <<" ";
	print_path(j, Set(mask, j));
}

int main()
{
	cout << "No. of citis : ";
	cin >> no_of_cities;
	
	cout << "Enter the cost matrix :" << endl;
	for (int i = 0; i < no_of_cities; i++)
		for (int j = 0; j < no_of_cities; j++)
			cin >> edge[i][j];

	memset(dp, -1, sizeof(dp));
	cout << "The minimum Cost will be : " << TSP(0,Set(0,0))<<endl;
	cout << "The shortest path is : 1 ";
	print_path(0, Set(0, 0));

	return 0;
}

/*
INPUT 01:
No. of citis : 3
Enter the cost matrix :
0 2 3
4 0 5
6 7 0
The minimum Cost will be : 13
The shortest path is : 1 2 3 1

INPUT 02:
No. of citis : 4
Enter the cost matrix :
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0
The minimum Cost will be : 35
The shortest path is : 1 2 4 3 1

INPUT 03:
No. of citis : 4
Enter the cost matrix :
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
The minimum Cost will be : 80
The shortest path is : 1 2 4 3 1
*/