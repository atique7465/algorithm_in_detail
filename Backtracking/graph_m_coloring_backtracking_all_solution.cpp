/// resource 01: https://www.youtube.com/watch?v=052VkKhIaQ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=66
/// resource 02: https://www.geeksforgeeks.org/graph-coloring-applications/

/// problem statement : Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints.
///                     01. is it possible to color this graph with m color ? 
///                     02. how many ways and what are the colors with m colors ? 
///                     03. minimum number of colors to color the graph. just save the minimum m.
/// this code will give output all possible solution if its possible to color the vertices with m different colors.

/// time complexity O(n * m^n ). n is num. of vertices, m is num. of colors

#include<bits/stdc++.h>
#define mx  21
using namespace std;
int amount, no_of_nodes, no_of_edges, m, u, v, colors[mx], cnt = 1;
vector<int>adj_list[mx];

void print_solution()
{
	cout << endl << "Soution " << cnt << " :" << endl;
	for (int i = 1; i <= no_of_nodes; i++)
		cout << colors[i] << " ";
	cout << endl;
	cnt++;
}

bool isSafe(int v, int color)
{
	for (int i = 0; i < adj_list[v].size(); i++)
		if (colors[adj_list[v][i]] == color)
			return false;
	return true;
}

bool m_coloring(int v)
{
	if (v > no_of_nodes)
	{
		print_solution();
		return true;
	}

	int res = false;

	for (int i = 1; i <= m; i++)
	{
		if (isSafe(v, i))
		{
			colors[v] = i;
			res = res | m_coloring(v + 1); /// return after this line for only one solution.
			colors[v] = 0;  /// backtrack.
		}
	}

	return res;
}

int main()
{
	cout << "Number of nodes : ";
	cin >> no_of_nodes;
	cout << "Number of edges : ";
	cin >> no_of_edges;
	cout << "enter the edges as start end pair :"<<endl;
	for (int i = 1; i <= no_of_edges; i++)
	{
		cin >> u >> v;
		adj_list[u].push_back(v);
		adj_list[v].push_back(u);
	}

	cout << "Enter the No. of colors : ";
	cin >> m;
	if (!m_coloring(1))
		cout << endl << "Not Possible!" << endl;

	return 0;
}

/*
INPUT 01:
Number of nodes : 4
Number of edges : 4
enter the edges as start end pair :
1 2
2 3
3 4
4 1
Enter the No. of colors : 3

Soution 1 :
1 2 1 2

Soution 2 :
1 2 1 3

Soution 3 :
1 2 3 2

Soution 4 :
1 3 1 2

Soution 5 :
1 3 1 3

Soution 6 :
1 3 2 3

Soution 7 :
2 1 2 1

Soution 8 :
2 1 2 3

Soution 9 :
2 1 3 1

Soution 10 :
2 3 1 3

Soution 11 :
2 3 2 1

Soution 12 :
2 3 2 3

Soution 13 :
3 1 2 1

Soution 14 :
3 1 3 1

Soution 15 :
3 1 3 2

Soution 16 :
3 2 1 2

Soution 17 :
3 2 3 1

Soution 18 :
3 2 3 2

INPUT 02:
Number of nodes : 4
Number of edges : 4
enter the edges as start end pair :
1 2
1 3
2 3
3 4
Enter the No. of colors : 3

Soution 1 :
1 2 3 1

Soution 2 :
1 2 3 2

Soution 3 :
1 3 2 1

Soution 4 :
1 3 2 3

Soution 5 :
2 1 3 1

Soution 6 :
2 1 3 2

Soution 7 :
2 3 1 2

Soution 8 :
2 3 1 3

Soution 9 :
3 1 2 1

Soution 10 :
3 1 2 3

Soution 11 :
3 2 1 2

Soution 12 :
3 2 1 3
*/
