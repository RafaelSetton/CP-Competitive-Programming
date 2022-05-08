#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;
int n, c, t, temp;
int pipocas[MAX];

bool possible(long long m)
{
    long long qtd = m * t, tot = 0, players = c;
    int i = 0;
    while (players > 0)
    {
        while (tot + pipocas[i] <= qtd)
        {
            tot += pipocas[i];
            i++;
            if (i >= n)
                return true;
        }
        players--;
        tot = 0;
    }
    return i >= n;
}

int main()
{

    cin >> n >> c >> t;

    for (int i = 0; i < n; i++)
    {
        cin >> pipocas[i];
    }
    int l = 0, r = 1e9 + 1;
    while (l < r)
    {
        int m = (l + r) / 2;
        if (possible(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
    return 0;
}