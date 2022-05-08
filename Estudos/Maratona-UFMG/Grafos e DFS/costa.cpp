#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;
    char temp;

    cin >> m >> n;
    vector<vector<char>> mapa(m);
    set<pair<int, int>> costa;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            mapa[i].push_back(temp);

            bool valid = (i == n - 1) || (i == 0) || (j == m - 1) || (j == 0);
            if (i > 0)
                valid += mapa[i - 1][j] != temp;
            if (j > 0)
                valid += mapa[i][j - 1] != temp;

            if (valid)
            {
                if (temp == '#')
                    costa.insert(pair<int, int>(i, j));
                else
                {
                    if (i > 0)
                        if (mapa[i - 1][j] == '#')
                            costa.insert(pair<int, int>(i - 1, j));
                    if (j > 0)
                        if (mapa[i][j - 1] == '#')
                            costa.insert(pair<int, int>(i, j - 1));
                }
            }
        }
    }

    cout << costa.size();

    return 0;
}