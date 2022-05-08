#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

void print(vector<pair<int, int>> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i].f << " " << v[i].s << endl;
}

int main()
{
    int n, ini, fim, now, count = 1;
    cin >> n;
    vector<pair<int, int>> reservas;

    for (int i = 0; i < n; i++)
    {
        cin >> ini >> fim;
        reservas.push_back({ini, fim});
    }
   
    sort(reservas.begin(), reservas.end());
    
    now = reservas.back().first;

    for (int i = n - 1; i >= 0; i--)
    {
        auto p = reservas[i];
        if (p.s < now)
        {
            now = p.f;
            count++;
        }
    }

    cout << count << endl;

    return 0;
}