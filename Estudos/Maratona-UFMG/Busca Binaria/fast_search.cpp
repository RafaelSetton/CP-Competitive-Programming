#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> arr;

int search_f(int i)
{
    int l = 0, r = n - 1, m;
    while (l < r)
    {
        m = (l + r) / 2;
        if (arr[m] >= i)
            r = m;
        else
            l = m + 1;
    }
    return l;
}
int search_l(int i)
{
    int l = 0, r = n - 1, m;
    while (l < r)
    {
        m = (l + r + 1) / 2;
        if (arr[m] > i)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

int main()
{
    int temp;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    int k, l, r;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> l >> r;
        int first = search_f(l);
        int last = search_l(r);
        // cout << f.first << " " << f.second << " " << l.first << " " << l.second << '\n';
        // cout << first << " " << last << endl;
        cout << max(last - first + (arr[last] <= r), 0) << " ";
    }
    cout << endl;

    return 0;
}