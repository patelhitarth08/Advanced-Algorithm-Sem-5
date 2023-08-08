#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string str = "THIS IS TEST STRING FOR TEST CASE";
    string pattern = "TEST";

    int n = str.length();
    int m = pattern.length();

    unordered_map<char, int> map;
    for (int i = 0; i < 26; i++)
        map['A' + i] = m;
    map[' '] = m;
    for (int i = 0; i < m - 1; i++) 
        map[pattern[i]] = m - i - 1;

    int i = m - 1;
    while (i < n)
    {
        if (str[i] == pattern[m - 1])
        {
            int j;
            for (j = 1; j < m; j++)
            {
                if (str[i - j] != pattern[m - j - 1])
                    break;
            }

            if (j == m)
                cout << "pattern found at " << i - m + 2 << endl;
            
        }
        i += map[str[i]];
    }

    return 0;
}
