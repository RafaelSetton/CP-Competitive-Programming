#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, x, n, m;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> x >> n >> m;
        while (x >= 20 && n > 0)
        {
            x = x / 2 + 10;
            n--;
        }
        while (x > 0 && m > 0)
        {
            x -= 10;
            m--;
        }
        cout << (x <= 0 ? "YES" : "NO") << endl;
    }
    return 0;
}