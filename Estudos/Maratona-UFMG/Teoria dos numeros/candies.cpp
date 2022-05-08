#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int pot = 4;
        for (int k = 0; k < n; k++)
        {
            if (n % (pot - 1) == 0)
            {
                cout << n / (pot - 1) << endl;
                break;
            }
            pot *= 2;
        }
    }

    return 0;
}