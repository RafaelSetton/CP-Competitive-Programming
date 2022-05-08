#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        long long x, y, a, b, v = 0;
        cin >> x >> y >> a >> b;
        if (b >= 2 * a)
        {
            cout << (abs(x) + abs(y)) * a << endl;
        }
        else if ((x >= 0 && y >= 0) || (x <= 0 && y <= 0))
        {
            cout << abs(min(x, y)) * b + abs(x - y) * a << endl;
        }
        else
        {
            cout << abs(x - y) * a << endl;
        }
    }
    return 0;
}