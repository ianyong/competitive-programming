#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<double, int> pdi;
#define MAX_N 10000

int n, m, x, y;
double f, maxSize[MAX_N];
bool visited[MAX_N];
vector<pdi> adjList[MAX_N];
priority_queue<pdi> pq;

int main() {
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            adjList[i].clear();
            maxSize[i] = 0.0;
            visited[i] = false;
        }
        for (int i = 0; i < m; i++) {
            scanf("%d %d %lf", &x, &y, &f);
            adjList[x].push_back(make_pair(f, y));
            adjList[y].push_back(make_pair(f, x));
        }
        // Modified Dijkstra's algorithm
        maxSize[0] = 1.0;
        pq.push(make_pair(maxSize[0], 0));
        while (!pq.empty()) {
            double factor = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();
            // Factors are <= 1 so each vertex needs to be visited only once
            if (visited[vertex]) continue;
            visited[vertex] = true;
            for (int i = 0; i < adjList[vertex].size(); i++) {
                int nextVertex = adjList[vertex][i].second;
                factor = adjList[vertex][i].first;
                if (maxSize[vertex] * factor > maxSize[nextVertex]) {
                    maxSize[nextVertex] = maxSize[vertex] * factor;
                    pq.push(make_pair(maxSize[nextVertex], nextVertex));
                }
            }
        }
        printf("%.4lf\n", maxSize[n - 1]);
    }
}