#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

int n, g;
ull d, c;
vector<pair<ull, ull>> gasStations;

int main() {
    scanf("%d %d", &n, &g);
    for (int i = 0; i < n; i++) {
        scanf("%llu %llu", &d, &c);
        gasStations.push_back(make_pair(d, c));
    }
    // Sort by distance
    sort(gasStations.begin(), gasStations.end());
    int pos = 0, fuel = g - gasStations[0].first;
    ull cost = 0;
    if (g >= gasStations[0].first) {
        while (true) {
            // Last gas station reached
            if (pos == n - 1) {
                printf("%llu", cost);
                break;
            }
            // To prevent overbuying of fuel
            if (g > gasStations[n - 1].first - gasStations[pos].first)
                g = gasStations[n - 1].first - gasStations[pos].first;
            // Impossible
            if (gasStations[pos + 1].first - gasStations[pos].first > g) {
                printf("cancel road trip");
                break;
            }
            int nextCheapest = 0;
            // Find the next cheapest gas station within g kilometers
            for (int i = 1; pos + i < n; i++) {
                if (gasStations[pos + i].first - gasStations[pos].first > g)
                    break;
                if (gasStations[pos + i].second < gasStations[pos].second) {
                    nextCheapest = i;
                    break;
                }
            }
            if (!nextCheapest) { // Max the fuel tank if the current gas station is the cheapest
                cost += (g - fuel) * gasStations[pos].second;
                fuel = g;
                nextCheapest = 1;
            } else {
                ull nextDistance = gasStations[pos + nextCheapest].first - gasStations[pos].first;
                if (nextDistance > fuel) {
                    cost += (nextDistance - fuel) * gasStations[pos].second;
                    fuel = nextDistance;
                }
            }
            fuel -= gasStations[pos + nextCheapest].first - gasStations[pos].first;
            pos += nextCheapest;
        }
    } else printf("cancel road trip");
}