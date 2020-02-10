/// Resource 01: https://www.youtube.com/watch?v=BNEVpkwYqpk&list=PLjhq5EHRYAeJc6-oMw43yxY6LtieTNV9a&index=7
/// Resource 02: https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/

#include<bits/stdc++.h>
#define mx 21
using namespace std;
int maze_row, maze_col, visited[mx][mx],maze[mx][mx],source_row, source_col, dest_row, dest_col, path_value, cnt = 1;

int drow[] = { 0, 0, 1, -1};
int dcol[] = { 1, -1, 0, 0};

void print_solution()
{
    cout << endl <<"Solution " << cnt << ":" << endl;
    for (int i = 0; i < maze_row; i++) 
    {
        for (int j = 0; j < maze_row; j++)
            cout << visited[i][j] << " ";
        cout << endl;
    }
    cnt++;
}

bool isSafe(int newrow, int newcol)
{
    if (newrow >= 0 && newrow < maze_row && newcol >= 0 && newcol < maze_col && !visited[newrow][newcol] && maze[newrow][newcol])
        return true;
    else
        return false;
}

bool Rat_in_maze(int row, int col)
{
    if (row == dest_row && col == dest_col)
    {
        print_solution();
        return true;
    }

    bool res = false;

    for (int i = 0; i < 4; i++)
    {
        int newrow = row + drow[i];
        int newcol = col + dcol[i];
        if (isSafe(newrow, newcol))
        {
            visited[newrow][newcol] = ++path_value;
            res = res | Rat_in_maze(newrow, newcol);
            visited[newrow][newcol] = 0;     /// backtrack.
            path_value--;
        }
    }
    return res;
}


int main()
{
    cout << "Enter the Maze size in row column pair : ";
    cin >> maze_row >> maze_col;

    cout << "Enter the Maze :" << endl;
    for (int i = 0; i < maze_row; i++)
        for (int j = 0; j < maze_col; j++)
            cin >> maze[i][j];

    cout << "Enter the Source in row column pair : ";
    cin >> source_row >> source_col;

    cout << "Enter the Destination in row column pair : ";
    cin >> dest_row >> dest_col;

    path_value = 1;
    visited[source_row][source_col] = path_value;
    if (!Rat_in_maze(source_row, source_col))
        cout << "No path found!" << endl;

    return 0;
}

/*
INPUT 01:
Enter the Maze size in row column pair : 4 4
Enter the Maze :
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
Enter the Source in row column pair : 0 0
Enter the Destination in row column pair : 3 3

Solution 1:
1 0 0 0
2 3 0 0
0 4 0 0
0 5 6 7

INPUT 02:
Enter the Maze size in row column pair : 4 4
Enter the Maze :
1 1 0 1
0 1 1 1
0 1 0 1
0 1 1 1
Enter the Source in row column pair : 0 0
Enter the Destination in row column pair : 3 3

Solution 1:
1 2 0 0
0 3 4 5
0 0 0 6
0 0 0 7

Solution 2:
1 2 0 0
0 3 0 0
0 4 0 0
0 5 6 7
*/