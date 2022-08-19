#include <cstdio>
using namespace std;

int a, b, c, n;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &n);
    if (a >= 1 && b >= 1 && c >= 1 && (a + b + c) >= n && n >= 3) {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
}
