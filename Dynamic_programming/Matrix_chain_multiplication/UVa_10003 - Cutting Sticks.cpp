/*
idea : http://andrew-algorithm.blogspot.com/2014/11/uva-problem-10003-cutting-sticks.html
First notice this problem is an 'ordering' problem. We are trying to find an order. To determine an order you make a choice which one is the first one to go, and then which is next, and so on.

A little fiddling make me realize the sub-problems are overlapped. It doesn't matter how I get to the state of cutting a stick from the mth endpoint to the nth endpoint, I just have to solve that sub-problem optimally.

So in the view of this, we define the recurrence relation as follow

Let opt(m, n) be the minimal cost of cutting the stick from the mth endpoint to the nth endpoint.

Base case, we have opt(m, m+1) = 0, because there is no need to cut a segment with no internal endpoints.

Inductively, we have opt(m, n) = endpoints(n) - endpoint(m) + min over k (opt(m, k) + opt(k, n)). We have to make a cut anyway and that will always cost us endpoints(n) - endpoint(m) independent on where we choose, and we need to choose one, that minimize subsequent costs.

That's it, given the recurrence formula we can code up the bottom up DP easily.
*/

#include<bits/stdc++.h>
#define mx 51
using namespace std;
int n, cut[mx], dp[mx][mx],L;

int min_computation(int beg, int end)
{
	if (end - beg == 1)
		return 0;

	if (dp[beg][end] != -1)
		return dp[beg][end];
    
	int res = INT_MAX;
	for (int mid = beg + 1 ; mid < end; mid++)
	{
		 res = min( res , min_computation(beg, mid) + min_computation(mid , end) + cut[end] - cut[beg] );
	}
	return dp[beg][end] = res;
}

int main()
{
	while (cin >> L)
	{
		if (L == 0)
			break;
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> cut[i];

		cut[n + 1] = L;

		memset(dp, -1, sizeof(dp));

		cout <<"The minimum cutting is "<<min_computation(0, n+1) <<"." <<endl;
	}
	return 0;
}
