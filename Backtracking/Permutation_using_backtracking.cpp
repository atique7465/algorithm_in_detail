/// bitmasking may use.

#include<bits/stdc++.h>
using namespace std;
int used[20], cnt;
string s, par;
map<string, int>m;

void permutation(int at)
{
    if (at >= s.size())
    {
        if (!m.count(par))
        {
            m[par] = 1;  /// to handle duplicat.
            cout << par << endl;
            cnt++;
        }
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            par.push_back(s[i]);
            permutation(at + 1);
            par.pop_back();
            used[i] = 0;
        }
    }
}

int main()
{
    cout << "enter the string to get permutation of its characters : ";
    cin >> s;
    cnt = 0;
    permutation(0);
    cout << "total number of purmutation= " << cnt;
    return 0;
}
