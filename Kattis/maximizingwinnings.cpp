#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 50
#define MAX_M 5001

int n, m, adjMatrix[MAX_N][MAX_N], memo[MAX_N][MAX_M][2];

int dp(int room, int turns, bool mode);

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &adjMatrix[i][j]);
        scanf("%d", &m);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= m; j++) {
                memo[i][j][0] = INT_MAX;
                memo[i][j][1] = INT_MIN;
            }
        }
        printf("%d %d\n", dp(0, m, true), dp(0, m, false));
    }
}

int dp(int room, int turns, bool mode) {
    if (!turns) return 0;
    if (memo[room][turns][mode] != (mode ? INT_MIN : INT_MAX)) return memo[room][turns][mode];
    int result = mode ? INT_MIN : INT_MAX;
    for (int i = 0; i < n; i++) {
        if (mode) result = max(dp(i, turns - 1, mode) + adjMatrix[room][i], result);
        else result = min(dp(i, turns - 1, mode) + adjMatrix[room][i], result);
    }
    return memo[room][turns][mode] = result;
}