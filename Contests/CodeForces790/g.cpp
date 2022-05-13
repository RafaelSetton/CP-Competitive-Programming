#include <bits/stdc++.h>

using namespace std;

const int MAX = 4010;

vector<vector<int>> children(MAX);
char colors[MAX];
int balanced;

int dfs(int from) {
    int soma = (colors[from] == 'B' ? 1 : -1);
    for (auto to : children[from]) 
        soma += dfs(to);
    
    if (soma == 0) balanced++;
    return soma;
}

int main() {
    int t, n, temp; cin >> t;
    for (int i=0; i<t; i++) {
        cin >> n;
        balanced = 0;
        children = vector<vector<int>>(MAX);
        for (int j=2; j<n+1; j++) {
            cin >> temp;
            children[temp].push_back(j);
        }
        for (int j=1; j<n+1; j++) cin >> colors[j];
        dfs(1);
        cout << balanced << endl;
    }
    return 0;
}