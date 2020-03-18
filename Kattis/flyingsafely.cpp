#include <cstdio>
using namespace std;

int numOfTestCases, n, m;

int main() {
    scanf("%d", &numOfTestCases);
    for (int i = 0; i < numOfTestCases; i++) {
        scanf("%d %d", &n, &m);
        printf("%d\n", n - 1);
        for (int j = 0; j < m; j++)
            scanf("%*d %*d");
    }
}