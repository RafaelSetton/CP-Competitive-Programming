#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int a, b, p = pow(2, n / 2);
        a = 2 * (p / 2 - 1) + p * p;
        b = p * (p - 1);
        cout << abs(a - b) << endl;
    }
    return 0;
}