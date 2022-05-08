#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, a;
        cin >> n;
        vector<long long> seq;
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            seq.push_back(a);
        }

        long long sign = seq[0], sum = 0, next = seq[0];
        for (int j = 1; j < n; j++)
        {
            if ((seq[j] ^ sign) < 0)
            {
                sum += next;
                sign = seq[j];
                next = seq[j];
                // cout << "sum, sign, next " << sum << ", " << sign << ", " << next << endl;
            }
            else
                next = max(seq[j], next);
        }
        if ((seq.back() ^ sign) >= 0)
            sum += next;
        cout << sum << endl;
    }

    return 0;
}