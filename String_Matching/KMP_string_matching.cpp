/// resource 01: https://www.youtube.com/watch?v=V5-7GzOfADQ&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=74
/// resource 02: http://www.shafaetsplanet.com/?p=3209
/// time complexity is linear -> O( n + m ). n for text size & m for pattern size;

#include<bits/stdc++.h>
using namespace std;
int failure[101];

void find_failor(string pattern)
{
	failure[0] = failure[1] = 0;

	for (int i = 2; i <= pattern.size(); i++)
	{
		int j = failure[i - 1];  /// as string indexing starts from 0 so, j in place of j+1 and i-1 for i.
		while (1)
		{
			if (pattern[j] == pattern[i - 1])
			{
				failure[i] = j + 1;
				break;
			}

			if (j == 0)
			{
				failure[i] = 0;
				break;
			}

			j = failure[j];
		}
	}
}

bool KMP(string text, string pattern)
{
	find_failor(pattern);

	int i = 0, j = 0;
	while (i<text.size() && j<pattern.size())
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
			if (j == pattern.size())
				return true;
		}
		else
		{
			if (j == 0)
				i++;
			else
				j = failure[j];
		}
	}
	return false;
}

int main()
{
	string text, pattern;
	cout << "Enter the text : ";
	cin >> text;
	cout << "Enter the pattern to be searched : ";
	cin >> pattern;

	if (KMP(text, pattern))
		cout << "Found!" << endl;
	else
		cout << "Not Found!" << endl;

	return 0;
}

/*
INPUT 01:
ababcabcabababd
ababd
Found!

INPUT 02:
ababcabcabababd
ababz
Not Found!

INPUT 03:
ababcabcabababd
a
Found!

INPUT 04:
ababcabcabababd
ababcabcabababd
Found!

INPUT 05:
ababcabcabababd
x
Not Found!
*/