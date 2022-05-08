#include <bits/stdc++.h>

using namespace std;

int main()
{
    int A, V, n = 1;
    while (true)
    {
        cin >> A >> V;
        if (A == 0 && V == 0)
            return 0;
        vector<int> vizinhos(A + 1);
        int x, y;
        for (int i = 0; i < V; i++)
        {
            cin >> x >> y;
            vizinhos[x]++;
            vizinhos[y]++;
        }
        int MAX = *max_element(vizinhos.begin(), vizinhos.end());
        cout << "Teste " << n << endl;
        for (int i = 1; i <= A; i++)
            if (vizinhos[i] == MAX)
                cout << i << " ";
        cout << "\n\n";
        n++;
    }

    return 0;
}