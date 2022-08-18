#include <cstdio>
using namespace std;

int numTestCases, n, m;

int main() {
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", (n / 3) * (m / 3));
    }
}
