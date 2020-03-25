#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_NODES 1000
#define MAX_EDGES 5000
#define INFINITY 1000000000

struct Edge {
    int u, v, w;
};

int n, m, q, s, u, v, w, edgeListIndex, dist[MAX_NODES];
Edge edgeList[MAX_EDGES];
bool unchanged;

int main() {
    while (true) {
        scanf("%d %d %d %d", &n, &m, &q, &s);
        if (n == 0) break;
        for (int i = 0; i < n; i++) dist[i] = INFINITY;
        dist[s] = 0;
        edgeListIndex = 0;
        unchanged = false;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            edgeList[edgeListIndex++] = {u, v, w};
        }
        // Bellman Ford's algorithm
        for (int i = 0; i < n - 1; i++) {
            unchanged = true;
            for (int j = 0; j < edgeListIndex; j++) {
                Edge edge = edgeList[j];
                if (dist[edge.u] != INFINITY && dist[edge.u] + edge.w < dist[edge.v]) {
                    dist[edge.v] = dist[edge.u] + edge.w;
                    unchanged = false;
                }
            }
            if (unchanged) break;
        }
        // Check for negative cycles
        if (!unchanged) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < edgeListIndex; j++) {
                    Edge edge = edgeList[j];
                    if (dist[edge.u] != INFINITY && dist[edge.u] + edge.w < dist[edge.v])
                        dist[edge.v] = -INFINITY;
                }
            }
        }
        for (int i = 0; i < q; i++) {
            scanf("%d", &u);
            if (dist[u] == INFINITY) printf("Impossible\n");
            else if (dist[u] == -INFINITY) printf("-Infinity\n");
            else printf("%d\n", dist[u]);
        }
        printf("\n");
    }
}