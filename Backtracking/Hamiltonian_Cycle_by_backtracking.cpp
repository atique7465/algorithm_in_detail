/// resource 01 : https://www.youtube.com/watch?v=dQr4wZCiJJ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=67
/// resource 02 : https://www.geeksforgeeks.org/travelling-salesman-problem-set-1/
/// problem statement : Given a graph. determine if there is any path start from starting node visits all other nodes
///                     once and return to satrting node. if possible then show all of the solutions. Kinda TSP.
/// time complexity : O(n!) or O(n^n). its an np hard problem.


#include<bits/stdc++.h>
#define mx 21
using namespace std;
int no_of_nodes, no_of_edges, u, v ,edge[mx][mx],start,cnt;
vector<int>path;

int Set(int x, int pos) { return x = x | (1 << pos); }
int ReSet(int x, int pos) { return x = x & (~(1 << pos)); }
bool check(int x, int pos) { return x & (1 << pos); }

void print_cycle()
{
	cout << endl << "Solution " << cnt << ": ";
	cout << start<< " ";
	for (int i = 0; i < path.size(); i++)
		cout << path[i] + 1 << " ";
	cout << start << endl;
	cnt++;
}

bool Hamiltonian_cycle(int i, int mask)
{
	if (mask == (1 << no_of_nodes) - 1)
	{
		if (edge[i][start-1])
		{
			print_cycle();
			return true;
		}
		else
			return false;
	}

	int res = false;
	for (int j = 0; j < no_of_nodes; j++)
	{
		if (edge[i][j] && !check(mask, j))
		{
			path.push_back(j);
			res = res | Hamiltonian_cycle(j, Set(mask, j));
			path.pop_back();   /// backtrack
		}
	}
	return res;
}

int main()
{
	cout << "No. of citis : ";
	cin >> no_of_nodes;

	cout << "No. of edges : ";
	cin >> no_of_edges;
	cout << "Enter the edges as start end pair :" << endl;
	for (int i = 0; i < no_of_edges; i++)
	{
		cin >> u >> v;
		edge[u-1][v-1] = 1;
		edge[v-1][u-1] = 1; /// dont use for directed graph.
	}

	while(1)
	{
		cout <<endl<< "Check for a starting node : ";
		cin >> start;
		cnt = 1;
		if (!Hamiltonian_cycle(start-1, Set(0,start-1)))
			cout << "There is no Hamiltonian Cycle!" << endl;
	}

	return 0;
}

/*
INPUT 01:
No. of citis : 6
No. of edges : 9
Enter the edges as start end pair :
1 2
1 3
1 6
2 3
2 5
2 6
3 4
4 5
5 6

Check for a starting node : 1

Solution 1: 1 2 3 4 5 6 1

Solution 2: 1 2 6 5 4 3 1

Solution 3: 1 3 4 5 2 6 1

Solution 4: 1 3 4 5 6 2 1

Solution 5: 1 6 2 5 4 3 1

Solution 6: 1 6 5 4 3 2 1

INPUT 02:
No. of citis : 5
No. of edges : 8
Enter the edges as start end pair :
1 2
1 3
1 5
2 3
2 4
2 5
3 4
4 5

Check for a starting node : 1

Solution 1: 1 2 3 4 5 1

Solution 2: 1 2 5 4 3 1

Solution 3: 1 3 2 4 5 1

Solution 4: 1 3 4 2 5 1

Solution 5: 1 3 4 5 2 1

Solution 6: 1 5 2 4 3 1

Solution 7: 1 5 4 2 3 1

Solution 8: 1 5 4 3 2 1

INPUT 03:
No. of citis : 6
No. of edges : 7
Enter the edges as start end pair :
1 2
1 3
2 4
3 4
3 5
3 6
5 6

Check for a starting node : 1
There is no Hamiltonian Cycle!

Check for a starting node : 2
There is no Hamiltonian Cycle!

Check for a starting node : 3
There is no Hamiltonian Cycle!

Check for a starting node : 4
There is no Hamiltonian Cycle!

Check for a starting node : 5
There is no Hamiltonian Cycle!

Check for a starting node : 6
There is no Hamiltonian Cycle!

[note: this graph has articulation pint so no cycle found for no vertices]

INPUT 04:
No. of citis : 6
No. of edges : 6
Enter the edges as start end pair :
1 2
1 3
2 4
3 4
4 5
4 6

Check for a starting node : 1
There is no Hamiltonian Cycle!

Check for a starting node : 2
There is no Hamiltonian Cycle!

Check for a starting node : 3
There is no Hamiltonian Cycle!

Check for a starting node : 4
There is no Hamiltonian Cycle!

Check for a starting node : 5
There is no Hamiltonian Cycle!

Check for a starting node : 6
There is no Hamiltonian Cycle!

[note: this graph has two pendant vertex 5 & 6 so no cycle found for no vertices]
*/
