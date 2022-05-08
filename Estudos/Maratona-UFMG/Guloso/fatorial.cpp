#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    vector<int> fat(11);
    fat[0] = 1;
    for (int i = 1; i <= 10; i++)
        fat[i] = fat[i - 1] * i;

    for (int i = 10; i > 0; i--)
    {
        int t = n / fat[i];
        count += t;
        n -= t * fat[i];
    }

    cout << count << endl;

    return 0;
}