#include <bits/stdc++.h>

using namespace std;


/**
 * Implementation of <b>"polynomial rolling hash function"</b><br>
 * Ref: https://cp-algorithms.com/string/string-hashing.html
 */
class StringHashing {
    const int p = 31;
    const int mod = 1e9 + 9;
    int len = 0;
    vector<long long> p_pow;
    vector<long long> h;

public:
    StringHashing(string str) {

        len = str.size();

        for (int i = 0; i < len; i++) {
            p_pow.push_back(i == 0 ? 1 : (p_pow[i - 1] * p) % mod);
        }

        for (int i = 0; i < len; i++) {
            h.push_back(((i == 0 ? 0 : h[i - 1]) + (str[i] - 'a' + 1) * p_pow[i]) % mod);
        }
    }

    long long getHash(int i, int j) {
        long long hash = (h[j] - (i == 0 ? 0 : h[i - 1]) + mod ) % mod;
        return (hash * p_pow[len - i - 1]) % mod;
    }
};

int main() {

    string str = "atiquratiqur";

    StringHashing *sh = new StringHashing(str);

    long long h1 = sh->getHash(0, 5);
    long long h2 = sh->getHash(6, 11);

    cout << "h1 = " << h2 << endl << "h2 = " << h2 << endl;

    if (h1 == h2) {
        cout << "String hashes are same";
    } else {
        cout << "String hashes are not same";
    }
}