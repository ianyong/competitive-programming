#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_NODES 150
#define INFINITY 1000000000

int n, m, q, u, v, w, adjMatrix[MAX_NODES][MAX_NODES];

int main() {
    while (true) {
        scanf("%d %d %d", &n, &m, &q);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) adjMatrix[i][j] = 0;
                else adjMatrix[i][j] = INFINITY;
            }
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            adjMatrix[u][v] = min(adjMatrix[u][v], w); // If there are duplicate edges, take the smallest
        }
        // Floyd Warshall's algorithm
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (adjMatrix[i][k] != INFINITY && adjMatrix[k][j] != INFINITY)
                        adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
        // Check for negative cycles
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (adjMatrix[k][k] < 0 && adjMatrix[i][k] != INFINITY && adjMatrix[k][j] != INFINITY)
                        adjMatrix[i][j] = -INFINITY;
        for (int i = 0; i < q; i++) {
            scanf("%d %d", &u, &v);
            if (adjMatrix[u][v] == INFINITY) printf("Impossible\n");
            else if (adjMatrix[u][v] == -INFINITY) printf("-Infinity\n");
            else printf("%d\n", adjMatrix[u][v]);
        }
        printf("\n");
    }
}