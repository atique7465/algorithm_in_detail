#include <bits/stdc++.h>

using namespace std;

/**
 * given 2 string s & t, find smallest substring in s where every char of t exist including duplicates
 * [elements are upper & lower case en letters]
 *
 * 01. increase end pointer and decrease need counter if we found a char that is needed to match
 * 02. if no other char needed to match update the min range
 * 03. its time to move forward start pointer and track if we skip any char which is needed
 */
class Solution_01 {
public:
    string fun(string s, string t) {

        int need = t.size(), sLen = s.size();
        vector<int> freq(128, 0);
        for (char c: t) freq[c]++;

        int minRange = INT_MAX, minStart = 0, start = 0, end = 0;
        while (end < sLen) {
            freq[s[end]]--;
            if (freq[s[end]] >= 0) need--;

            while (need == 0) {
                if (end - start + 1 < minRange) minRange = end - (minStart = start) + 1;

                freq[s[start]]++;
                if (freq[s[start]] > 0) need++;
                start++;
            }

            end++;
        }

        return minRange == INT_MAX ? "" : s.substr(minStart, minRange);
    }
};

/**
 * Longest Substring with At Most Two Distinct Characters
 * [elements are upper & lower case en letters]
 *
 * 01. increase end pointer and increase unique counter if we found a char that is just started to maintain unique char cnt
 * 02. if unique <= 2 update the max range as at most 2 unique char in this range
 * 03. its time to move forward start pointer if unique > 2 or unique char exceed 2 to make unique < 2
 */
class Solution_02 {
public:
    string fun(string s) {

        int unique = 0, sLen = s.size();
        vector<int> freq(128, 0);

        int maxRange = INT_MIN, maxStart = 0, start = 0, end = 0;
        while (end < sLen) {
            freq[s[end]]++;
            if (freq[s[end]] == 1) unique++;

            while (unique > 2) {
                freq[s[start]]--;
                if (freq[s[start]] == 0) unique--;
                start++;
            }

            if (end - start + 1 > maxRange) maxRange = end - (maxStart = start) + 1;

            end++;
        }

        return maxRange == INT_MIN ? "" : s.substr(maxStart, maxRange);
    }
};

/**
 * Longest Substring Without Repeating Characters
 * [elements are upper & lower case en letters]
 *
 * 01. increase end pointer and increase duplicate counter if we found a char which freq is > 1
 * 02. if duplicate == 0 update the max range as no duplicate char in this range
 * 03. its time to move forward start pointer if duplicate > 0
 */
class Solution_03 {
public:
    string fun(string s) {

        int duplicate = 0, sLen = s.size();
        vector<int> freq(128, 0);
        int maxRange = INT_MIN, maxStart = 0, start = 0, end = 0;
        while (end < sLen) {
            freq[s[end]]++;
            if (freq[s[end]] > 1) duplicate++;

            while (duplicate > 0) {
                freq[s[start]]--;
                if (freq[s[start]] > 0) duplicate--;
                start++;
            }

            if (end - start + 1 > maxRange) maxRange = end - (maxStart = start) + 1;

            end++;
        }

        return maxRange == INT_MIN ? "" : s.substr(maxStart, maxRange);
    }
};