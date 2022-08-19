#include <cstdio>
using namespace std;

int x, y;

int main() {
    scanf("%d %d", &x, &y);
    if (x > 0) {
        if (y > 0) {
            printf("1\n");
        } else {
            printf("4\n");
        }
    } else {
        if (y > 0) {
            printf("2\n");
        } else {
            printf("3\n");
        }
    }
}
