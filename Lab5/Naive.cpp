#include <bits/stdc++.h>
using namespace std;

int main () 
{
    string str = "THIS IS TEST STRING FOR TEST CASE";
    string pattern = "TEST S";

    int n = str.length();
    int m = pattern.length();

    for (int s = 0; s <= n - m; s++)
    {
        int i = 0, j = 0;
        while (j < m && str[s + i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Pattern found at shift: " << s << endl;
        }
    } 
    return 0;
}
