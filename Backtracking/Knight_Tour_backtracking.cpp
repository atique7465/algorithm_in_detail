/// Resource 01: https://www.youtube.com/watch?v=pwlxQeHchFQ&list=PLjhq5EHRYAeJc6-oMw43yxY6LtieTNV9a&index=8
/// Resource 02: https://www.geeksforgeeks.org/the-knights-tour-problem-backtracking-1/

#include<bits/stdc++.h>
#define mx 8
using namespace std;
int board_row, board_col, solution[mx][mx], cnt = 1;

int drow[] = { 2, 1, -1, -2, -2, -1,  1,  2 }; 
int dcol[] = { 1, 2,  2,  1, -1, -2, -2, -1 };

void print_solution()
{
    cout << endl <<"Solution " << cnt << ":" << endl;
    for (int i = 0; i < mx; i++) 
    {
        for (int j = 0; j < mx; j++)
            printf("%2d  ",solution[i][j]);
        cout << endl;
    }
    cnt++;
}

bool isSafe(int newrow, int newcol)
{
    if (newrow >= 0 && newrow < mx && newcol >= 0 && newcol < mx && solution[newrow][newcol] == -1)
        return true;
    else
        return false;
}

bool Knigt_Tour(int row, int col, int path_value)
{
    if (path_value == 64)
    {
        print_solution();
        return true;
    }

    for (int i = 0; i < mx; i++)
    {
        int newrow = row + drow[i];
        int newcol = col + dcol[i];
        if (isSafe(newrow, newcol))
        {
            solution[newrow][newcol] = path_value;
            if (Knigt_Tour(newrow, newcol, path_value + 1))
                return true;
            solution[newrow][newcol] = -1;     /// backtrack.
        }
    }
    return false;
}


int main()
{
    memset(solution, -1, sizeof(solution));

    solution[0][0] = 0;
    if (!Knigt_Tour(0, 0, 1))
        cout << "No path found!" << endl;

    return 0;
}

/*
INPUT 01:
Solution 1:
 0  59  38  33  30  17   8  63
37  34  31  60   9  62  29  16
58   1  36  39  32  27  18   7
35  48  41  26  61  10  15  28
42  57   2  49  40  23   6  19
47  50  45  54  25  20  11  14
56  43  52   3  22  13  24   5
51  46  55  44  53   4  21  12
*/