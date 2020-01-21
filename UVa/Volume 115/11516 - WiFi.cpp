#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_HOUSES 100000

bool coverable(double);

int n, m, houses[MAX_HOUSES];

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++) {
        scanf("%d%d", &n, &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &houses[j]);
        }
        if (n >= m) {
            printf("0.0\n");
            continue;
        }
        sort(houses, houses + m);
        double low = 0, high = houses[m - 1];
        while (high - low > 0.1) {
            double mid = (high + low) / 2;
            if (coverable(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        printf("%.1lf\n", round((high + low) / 2 * 10) / 10);
    }
}

bool coverable(double distance) {
    int num = n;
    double furthestDistance = houses[0] + distance * 2;
    for (int i = 1; i < m; i++) {
        if (furthestDistance < houses[i]) {
            furthestDistance = houses[i] + distance * 2;
            num--;
        }
    }
    return num >= 1;
}