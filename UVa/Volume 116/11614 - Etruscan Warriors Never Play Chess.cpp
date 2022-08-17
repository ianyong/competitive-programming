#include <cstdio>
#include <cmath>
using namespace std;

int numTestCases;
unsigned long long n;

int main() {
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        scanf("%lld", &n);
        printf("%d\n", ((int) sqrt(8 * n + 1) - 1) / 2);
    }
}
