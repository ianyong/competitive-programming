#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, t;
unsigned long long total;
vector<int> sizes;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        sizes.push_back(t);
    }
    sort(sizes.begin(), sizes.end());
    for (int j = 0; j < m; j++) {
        scanf("%d", &t);
        total += *lower_bound(sizes.begin(), sizes.end(), t) - t;
    }
    printf("%llu", total);
}