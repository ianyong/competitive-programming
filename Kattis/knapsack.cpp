// Previously, C was stated to be a real number. The problem statement states that C is an integer
// as of 11/06/2020. However, the test cases were not updated, resulting in runtime errors.
// Original problem statement:
// https://web.archive.org/web/20161220064727/https://open.kattis.com/problems/knapsack

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

#define MAX_N 2000
#define MAX_WEIGHT 2000

double C;
int c, n;
int value[MAX_N], weight[MAX_N], memo[MAX_N + 1][MAX_WEIGHT + 1];
stack<int> s;

int main() {
    while (scanf("%lf %d", &C, &n) != EOF) {
        c = C;
        for (int i = 0; i < n; i++) 
            scanf("%d %d", &value[i], &weight[i]);
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= c; j++) {
                if (i == 0 || j == 0) memo[i][j] = 0;
                else if (weight[i - 1] > j) memo[i][j] = memo[i - 1][j];
                else
                    memo[i][j] = max(memo[i - 1][j], value[i - 1] + memo[i - 1][j - weight[i - 1]]);
            }
        }
        
        int res = memo[n][c];
        for (int i = n - 1; i >= 0 && res > 0; i--) {
            if (res == memo[i][c]) continue;
            s.push(i);
            res -= value[i];
            c -= weight[i];
        }
        printf("%d\n", s.size());
        while (!s.empty()) {
            printf("%d ", s.top());
            s.pop();
        }
        printf("\n");
    }
}