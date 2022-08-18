#include <cstdio>
#include <cmath>
using namespace std;

long long a, b;

int main() {
    while (scanf("%lld %lld", &a, &b) != EOF) {
        printf("%lld\n", abs(a - b));
    }
}
