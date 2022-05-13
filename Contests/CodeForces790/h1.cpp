#include <bits/stdc++.h>

using namespace std;

const int MAX = 1010;

vector<int> a(MAX);



int main() {
    int t, n, cross; cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        cross = 0;
        for (int j=0; j<n; j++) {
            cin >> a[j];
            for (int k=0; k<j; k++) if (a[k] >= a[j]) cross++;            
        }
        cout << cross << endl;
    }
    return 0;
}