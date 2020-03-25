#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 1000001
#define VISITED -1
#define VISITING -2

int n, m, a, b;
int inDegree[MAX_N];
vector<int> adjList[MAX_N], order;
bool flag = true;

void dfs(int i);

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        adjList[a].push_back(b);
        inDegree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!inDegree[i]) dfs(i);
        if (!flag) break;
    }
    if (flag && order.size() == n)
        for (int i = n - 1; i >= 0; i--) printf("%d\n", order[i]);
    else printf("IMPOSSIBLE\n");
}

void dfs(int i) {
    if (inDegree[i] == VISITED) return;
    if (inDegree[i] == VISITING) {
        flag = false;
        return;
    }
    inDegree[i] = VISITING;
    for (int j : adjList[i]) dfs(j);
    inDegree[i] = VISITED;
    order.push_back(i);
}