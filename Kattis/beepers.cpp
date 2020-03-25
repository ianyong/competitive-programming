#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define MAX_N 11
#define NOT_COMPUTED -1

int m, n;
int x[MAX_N], y[MAX_N], dist[MAX_N][MAX_N], memo[MAX_N][1 << (MAX_N - 1)];

int dp(int pos, int mask);

int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%*d %*d %d %d %d", &x[0], &y[0], &n);
        n++;
        for (int j = 1; j < n; j++) {
            scanf("%d %d", &x[j], &y[j]);
        }
        for (int i = 0; i < MAX_N; i++) {
            for (int j = i; j < MAX_N; j++) {
                dist[i][j] = dist[j][i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            }
        }
        memset(memo, -1, sizeof(memo));
        printf("%d\n", dp(0, (1 << (n - 1)) - 1));
    }
}

int dp(int pos, int mask) {
    if (mask == 0) return dist[pos][0];
    if (memo[pos][mask] != NOT_COMPUTED) return memo[pos][mask];
    int result = INT_MAX;
    for (int i = 1; i < n; i++) {
        int andMask = 1 << (i - 1);
        if (mask & andMask) {
            result = min(result, dist[pos][i] + dp(i, mask ^ andMask));
        }
    }
    return memo[pos][mask] = result;
}