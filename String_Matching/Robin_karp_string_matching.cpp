/// resource 01: https://www.youtube.com/watch?v=qQ8vS2btsxI&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=75
/// resource 02: http://www.shafaetsplanet.com/?p=3028
/// time complexity: O(n - m + 1) for average case. for worst case it is O(n*m) because of hash colission. 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll Hash_Function(string s, ll m, ll B, ll mod)
{
	ll hash_value = 0, power = 1;
	for (int i = m - 1; i >= 0; i--)
	{
		hash_value = hash_value + (s[i] * power) % mod;
		hash_value = hash_value % mod;
		power = (power * B) % mod;
	}
	return hash_value;
}

int Robin_Karp(string text, string pattern)
{
	ll n = text.size();
	ll m = pattern.size();

	if (m > n || n == 0 || m == 0)
		return -1;

	ll B = 331, mod = 1000000000 + 7;
	ll mx_power = 1;
	for (int i = 1; i < m; i++)
		mx_power *= B;

	ll hash_pattern = Hash_Function(pattern, m, B, mod);
	ll hash_text = Hash_Function(text, m, B, mod);

	if (hash_pattern == hash_text)
		return 0;

	for (int i = m; i < n; i++)
	{
		hash_text = (hash_text - (text[i - m] * mx_power)) % mod;
		hash_text = (hash_text + mod) % mod;
		hash_text = (hash_text * B) % mod;
		hash_text = (hash_text + text[i]) % mod;

		if (hash_pattern == hash_text)
			return i - m + 1;
	}
	return -1;
}

int main()
{

	string text, pattern;
	cout << "Enter the text : ";
	cin >> text;
	cout << "Enter the pattern to be searched : ";
	cin >> pattern;

	ll pos = Robin_Karp(text, pattern);
	if (pos != -1)
		cout << "Found at index : " << pos << endl;
	else
		cout<<"Not found!"<<endl;
	return 0;
}

/*
INPUT 01:
ababcabcabababd
ababd
Found at index : 10

INPUT 02:
ababcabcabababd
ababz
Not Found!

INPUT 03:
ababcabcabababd
a
Found at index : 0

INPUT 04:
ababcabcabababd
ababcabcabababd
Found at index : 0

INPUT 05:
ababcabcabababd
x
Not Found!
*/