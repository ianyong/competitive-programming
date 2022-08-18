#include <cstdio>
using namespace std;

int N;
double q, y, total;

int main() {
    scanf("%d", &N);
    while (N--) {
        scanf("%lf %lf", &q, &y);
        total += q * y;
    }
    printf("%.3lf\n", total);
}
