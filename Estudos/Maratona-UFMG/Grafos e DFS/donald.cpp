#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<string, string>> nyt(n), donald(m);
    string temp;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);

        nyt.push_back({
            temp.substr(0, temp.find_first_of(' ')),
            temp.substr(temp.find_last_of(' '), temp.size()),
        });
    }
    for (int i = 0; i < m; i++)
    {
        getline(cin, temp);

        string f = temp.substr(0, temp.find_first_of(' ')),
               s = temp.substr(temp.find_last_of(' '), temp.size());

        if (find(nyt.begin(), nyt.end(), pair<string, string>(f, s)) != nyt.end())
            cout << "Fact\n";
        else if (find(nyt.begin(), nyt.end(), pair<string, string>(s, f)) != nyt.end())
            cout << "Alternative Fact\n";
        else
            cout << "Pants on Fire\n";
    }

    return 0;
}