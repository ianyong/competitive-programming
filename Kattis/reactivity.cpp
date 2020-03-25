#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 1000
#define VISITED -1

int N, K, A, B, orderIndex = 0, inDegree[MAX_N], order[MAX_N];
bool adjMatrix[MAX_N][MAX_N];

void dfs(int i);

int main() {
    scanf("%d %d", &N, &K);
    if (K < N - 1) {
        printf("back to the lab");
        return 0;
    }
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &A, &B);
        adjMatrix[B][A] = true;
        inDegree[A]++;
    }
    for (int i = 0; i < N; i++) {
        if (!inDegree[i]) dfs(i);
    }
    for (int i = 1; i < N; i++) {
        if (!adjMatrix[order[i]][order[i - 1]]) {
            printf("back to the lab");
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%d ", order[i]);
    }
}

void dfs(int i) {
    if (inDegree[i] == VISITED) return;
    inDegree[i] = VISITED;
    for (int j = 0; j < N; j++) {
        if (adjMatrix[i][j]) dfs(j);
    }
    order[orderIndex++] = i;
}