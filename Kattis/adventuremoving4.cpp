#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define GAS_TANK_SIZE 200
#define MAX_GAS_STATIONS 100

int totalDist, dist, price, memo[MAX_GAS_STATIONS][GAS_TANK_SIZE];
vector<pair<int, int>> gasStations;
bool possible, visited[MAX_GAS_STATIONS][GAS_TANK_SIZE];

int dp(int pos, int fuel);

int main() {
    scanf("%d", &totalDist);
    while (scanf("%d %d", &dist, &price) != -1) {
        gasStations.push_back(make_pair(dist, price));
    }
    gasStations.push_back(make_pair(totalDist + GAS_TANK_SIZE / 2, INT_MAX));
    if (GAS_TANK_SIZE / 2 - gasStations[0].first >= 0)
        price = dp(0, GAS_TANK_SIZE / 2 - gasStations[0].first);
    if (possible) printf("%d", price);
    else printf("Impossible");
}

int dp(int pos, int fuel) {
    // Big city reached with at least half full tank of gas
    if (pos == gasStations.size() - 1) {
        possible = true;
        return 0;
    }
    if (visited[pos][fuel]) return memo[pos][fuel];
    visited[pos][fuel] = true;
    int minCost = INT_MAX;
    for (int i = 1; pos + i < gasStations.size(); i++) {
        int nextDist = gasStations[pos + i].first - gasStations[pos].first;
        if (nextDist > 200) break;
        if (fuel >= nextDist) { // Sufficient fuel to reach destination
            minCost = min(minCost, min(dp(pos + i, fuel - nextDist),
                    dp(pos + i, GAS_TANK_SIZE - nextDist) + gasStations[pos].second * (GAS_TANK_SIZE - fuel)));
        } else { // Insufficient fuel to reach destination
            minCost = min(minCost, min(dp(pos + i, 0) + gasStations[pos].second * (nextDist - fuel),
                    dp(pos + i, GAS_TANK_SIZE - nextDist) + gasStations[pos].second * (GAS_TANK_SIZE - fuel)));
        }
    }
    return memo[pos][fuel] = max(minCost, 0);
}