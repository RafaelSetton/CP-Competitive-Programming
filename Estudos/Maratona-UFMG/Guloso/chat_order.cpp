#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string name;
    set<string> msgs;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        msgs.erase(name);
        msgs.insert(name);
    }
    while (!msgs.empty())
    {
        name = *msgs.rbegin();
        msgs.erase(name);
        cout << name << endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string name;
    vector<string> msgs, filtered;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        msgs.push_back(name);
    }
    while (!msgs.empty())
    {
        name = msgs.back();
        msgs.pop_back();
        if (!count(filtered.begin(), filtered.end(), name))
        {
            filtered.push_back(name);
            cout << name << endl;
        }
    }

    return 0;
}
*/