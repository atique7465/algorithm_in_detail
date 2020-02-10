#include<bits/stdc++.h>
using namespace std;
vector<int>edge[9],ans;
int status[6][6];

void santa_house(int u, int cnt)
{
	if (cnt == 8)
	{
		for (int j = 0; j < ans.size(); j++)
			cout << ans[j];
		cout << endl;
		return;
	}

	for (int i = 0; i < edge[u].size(); i++)
	{
		if (status[u][edge[u][i]] == 0)
		{
			ans.push_back(edge[u][i]);
			status[u][edge[u][i]] = status[edge[u][i]][u] = 1;
			santa_house(edge[u][i] , cnt + 1);
			ans.pop_back();
			status[u][edge[u][i]] = status[edge[u][i]][u] = 0;
		}
	}
}

int main()
{
	edge[1].push_back(2);
	edge[2].push_back(1);
	edge[1].push_back(3);
	edge[3].push_back(1);
	edge[1].push_back(5);
	edge[5].push_back(1);
	edge[2].push_back(3);
	edge[3].push_back(2);
	edge[2].push_back(5);
	edge[5].push_back(2);
	edge[3].push_back(4);
	edge[4].push_back(3);
	edge[3].push_back(5);
	edge[5].push_back(3);
	edge[5].push_back(4);
	edge[4].push_back(5);

	ans.push_back(1);
	santa_house(1, 0);

	return 0;
}