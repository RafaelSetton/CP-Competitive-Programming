#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> array, int n)
{
    int l = 0, r = array.size();
    while (l < r)
    {
        int m = (l + r) / 2;
        if (array[m] < n)
            l = m + 1;
        else
            r = m;
    }
    return array[l] == n;
}

int main()
{
    int n, k, temp;
    cin >> n >> k;
    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> temp;
        cout << (search(array, temp) ? "YES" : "NO") << endl;
    }

    return 0;
}