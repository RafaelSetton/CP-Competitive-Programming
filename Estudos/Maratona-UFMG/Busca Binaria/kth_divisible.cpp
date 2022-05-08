#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        unsigned int l = 0, r = 2 * k + 3, m;
        while (l < r)
        {
            m = (l + r) / 2;
            if (m - m / n >= k)
                r = m;
            else
                l = m + 1;
        }
        cout << l << endl;
    }
    return 0;
}