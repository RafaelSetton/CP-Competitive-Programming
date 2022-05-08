#include <bits/stdc++.h>

using namespace std;
vector<int> order, position(2e5 + 10), amount(2e5 + 10);
vector<vector<int>> subordinates(2e5 + 10);

int DFS(int x)
{
    order.push_back(x);
    int count = 1;
    for (int y : subordinates[x])
    {
        count += DFS(y);
    }
    amount[x] = count;
    return count;
}

int main()
{
    int n, q, ofc;
    cin >> n >> q; // 2e5

    for (int i = 2; i < n + 1; i++)
    {
        cin >> ofc;
        subordinates[ofc].push_back(i);
    }

    DFS(1);
    for (int i = 0; i < n; i++)
        position[order[i]] = i;

    for (int i = 0; i < q; i++)
    {
        int u, k;
        cin >> u >> k;
        if (k > amount[u])
            cout << -1 << endl;
        else
            cout << order[position[u] + k - 1] << endl;
    }

    return 0;
}