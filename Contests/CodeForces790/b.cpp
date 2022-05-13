#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, temp; cin >> t;
    int min_candies, eat;
    vector<int> candies(51);

    for (int i=0; i<t; i++) {
        cin >> n;
        min_candies = 1e8;
        eat = 0;
        for (int j=0; j<n; j++) {
            cin >> temp;
            min_candies = min(min_candies, temp);
            candies[j] = temp;
        }
        for (int j=0; j<n; j++) 
            eat += candies[j] - min_candies;
        
        cout << eat << endl;
    }
    return 0;
}