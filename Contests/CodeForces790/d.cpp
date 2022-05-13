#include <bits/stdc++.h>

using namespace std;

const int MAX = 201;

vector<vector<int>> mapa(MAX, vector<int>(MAX));
vector<int> up, down;


int main() {
    int t, n, m; cin >> t;
    int max_atk;
    for (int i=0; i<t; i++) {
        cin >> n >> m;
        up = vector<int>(2*MAX, 0), down = vector<int>(2*MAX, 0);
        for (int j=0; j<n; j++) 
            for (int k=0; k<m; k++) {
                cin >> mapa[j][k];
                up[j+k] += mapa[j][k];
                down[k-j+201] += mapa[j][k];
            }
        max_atk = 0; 
        for (int j=0; j<n; j++) 
            for (int k=0; k<m; k++) 
                max_atk = max(max_atk, up[j+k] + down[k-j+201] - mapa[j][k]);
            
        cout << max_atk << endl;
    }
    return 0;
}