#include <bits/stdc++.h>
using namespace std;

unsigned long long int gcd(unsigned long long int a,unsigned long long int b)
{
    if (a < b)
        return gcd(b, a);
    else if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

unsigned long long int power(unsigned long long int a, unsigned long long int n, unsigned long long int p) 
{
    unsigned long long int res = 1;
    a = a % p;

    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % p;
        n = n >> 1;
        a = (a * a) % p;
    }
    return res;
}

bool isPrime(unsigned long long int n)
{
    if (n <= 1 || n == 4)
        return false;

    if (n <= 3)
        return true;

    int k = 100;
    while (k--)
    {
        unsigned long long int a = 2 + rand() % (n - 4);

        if (gcd(n, a) != 1)
            return false;
        if (power(a, n - 1, n) != 1)
            return false;
    } 
    return true;
}

int main() 
{
    unsigned long long int num;
    cout << "Enter a number: " << endl;
    cin >> num;
    if (isPrime(num) == true)
        cout << num << " is a Prime number" << endl;
    else
        cout << num << " is not a Prime number" << endl;

    return 0;
}
