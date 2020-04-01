#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_C 200

int C, R, r1, r2;
double adjMatrix[MAX_C][MAX_C];
string c1, c2;
unordered_map<string, int> currencyMap;
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> C;
        if (C == 0) break;
        currencyMap.clear();
        for (int i = 0; i < C; i++)
            for (int j = 0; j < C; j++)
                adjMatrix[i][j] = 0.0;
        for (int i = 0; i < C; i++) {
            cin >> c1;
            currencyMap[c1] = i;
            adjMatrix[i][i] = 1.0;
        }
        cin >> R;
        for (int i = 0; i < R; i++) {
            cin >> c1 >> c2 >> r1;
            cin.ignore();
            cin >> r2;
            adjMatrix[currencyMap[c1]][currencyMap[c2]] = (double) r2 / r1;
        }
        // Floyd-Warshall's algorithm
        for (int k = 0; k < C; k++)
            for (int i = 0; i < C; i++)
                for (int j = 0; j < C; j++)
                    adjMatrix[i][j] = max(adjMatrix[i][j], adjMatrix[i][k] * adjMatrix[k][j]);
        flag = false;
        // Check for arbitrage
        for (int i = 0; i < C; i++) {
            if (adjMatrix[i][i] > 1.0) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "Arbitrage" : "Ok") << endl;
    }
}