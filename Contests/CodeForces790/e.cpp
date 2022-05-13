#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

vector<int> candies(MAX), prefix(MAX);
int n;

int bb(int x) {
    if (x > prefix[n-1]) return -1;
    int l=0, r=n-1, m;
    while (l < r) {
        m = (l+r)/2;
        if (prefix[m] >= x) r = m;
        else l = m+1;
    }
    return l + 1;
}

int main() {
    int t, q, x; cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n >> q;
        for (int j=0; j<n; j++) cin >> candies[j];
        sort(candies.begin(), candies.begin()+n, greater<>());
        prefix[0] = candies[0];
        for (int j=1; j<n; j++) 
            prefix[j] = prefix[j-1] + candies[j];
            
        for (int j=0; j<q; j++) {
            cin >> x;
            cout << bb(x) << endl;
        }
    }
    return 0;
}