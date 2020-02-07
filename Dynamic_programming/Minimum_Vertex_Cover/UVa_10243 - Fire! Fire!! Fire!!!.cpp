/// resource : http://www.shafaetsplanet.com/?p=582

#include<bits/stdc++.h>
#define mxnode 1000+1
using namespace std;
int no_of_nodes,u,v,parant[mxnode], dp[mxnode][2];
vector<int>edge[mxnode];

int MIN_VERTEX_COVER(int u, int guard)
{
	if (edge[u].size() == 0)
		return 0;

	if (dp[u][guard] != -1)
		return dp[u][guard];

	int sum = 0;

	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];
		if (v != parant[u])
		{
			parant[v] = u;
			if (guard == 0)
				sum += MIN_VERTEX_COVER(v, 1);
			else
				sum += min(MIN_VERTEX_COVER(v, 1), MIN_VERTEX_COVER(v, 0));
		}
	}
	return dp[u][guard] = sum + guard;
}

int main()
{
	while (cin >> no_of_nodes)
	{
		if (no_of_nodes == 0)
			break;

		memset(dp, -1, sizeof(dp));
        
		int adj;

		for (int i = 1; i <= no_of_nodes; i++)
		{
			cin >> adj;
			while (adj--)
			{
				cin >> v;
				edge[i].push_back(v);

			}
		}

		if (no_of_nodes < 2)
			cout << no_of_nodes << endl;
		else
			cout << min(MIN_VERTEX_COVER(1, 1), MIN_VERTEX_COVER(1, 0))<<endl;

		for(int i=0; i<=no_of_nodes; i++)
		    edge[i].clear();
	}

	return 0;
}
