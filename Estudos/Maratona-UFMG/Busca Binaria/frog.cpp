#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {
        char c;
        string rocks = "R";
        getline(cin, rocks);
        int m = 0, prev = -1;
        for (int j = 0; j < rocks.size(); j++)
        {
            if (rocks[j] == 'R')
            {
                m = max(m, j - prev);
                prev = j;
            }
        }
        cout << max(m, (int)rocks.size() - prev) << endl;
    }
    return 0;
}