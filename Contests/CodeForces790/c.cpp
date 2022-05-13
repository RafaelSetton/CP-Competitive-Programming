#include <bits/stdc++.h>

using namespace std;

int diff(string w1, string w2) {
    int d=0;
    for (int i=0; i<w1.size(); i++)
        d += abs(w1[i] - w2[i]);
    
    return d;
}

int main() {
    int t, n, m; cin >> t;
    int min_diff;
    string temp;
    vector<string> words(51);

    for (int i=0; i<t; i++) {
        cin >> n >> m;
        cin.ignore();
        for (int j=0; j<n; j++) {
            getline(cin, temp);
            words[j] = temp;
        }
        min_diff = 240; // > 8*26
        for (int j=0; j<n; j++) 
            for (int k=j+1; k<n; k++) {
                min_diff = min(min_diff, diff(words[j], words[k]));
            }
        
        cout << min_diff << endl;
    }
    return 0;
}