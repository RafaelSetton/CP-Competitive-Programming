#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n; cin >> t;
    string temp;
    cin.ignore();
    for (int i=0; i<t; i++) {
        getline(cin, temp);
        
        cout << (temp[0] + temp[1] + temp[2] == temp[3] + temp[4] + temp[5] ? "YES" : "NO") << endl;
    }
    return 0;
}