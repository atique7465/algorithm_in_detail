#include<bits/stdc++.h>
#define mx 50
using namespace std;
int status[mx], n;

int Set(int x, int pos) { return x = x | (1 << pos); }
int ReSet(int x, int pos) { return x = x & ~(1 << pos); }
int check(int x, int pos) { return x & (1 << pos); }

bool prime_check(int v)
{
	if ((v % 2 == 0 && v != 2) || v == 1)
		return false;

	for (int i = 2; i <= v - 1; i++)
		if (v % i == 0)
			return false;

	return true;
}

void print_solution(vector<int>ans)
{
	for (int i = 0; i < ans.size() - 1; i++)
		cout << ans[i] << " ";
	cout << ans[ans.size() - 1] << endl;
}

void RING(int mask, vector<int>ans)
{
	if (mask == (1 << n) - 1)
	{
		if (prime_check(1 + ans[ans.size() - 1]))
			print_solution(ans);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check(mask, i) && prime_check(ans[ans.size() - 1] + i + 1))
		{
			ans.push_back(i + 1);
			RING(Set(mask, i), ans);
			ans.pop_back();
		}
	}
}

int main()
{
	int cas = 1;
	while (cin >> n)
	{
		if (cas != 1)
			cout << endl;
		cout << "Case " << cas << ":" << endl;
		if (n > 0)
		{
			vector<int>ans;
			ans.push_back(1);
			RING(Set(0, 0), ans);
		}
		cas++;
	}

	return 0;
}