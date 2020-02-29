#include <cstdio>
using namespace std;

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

int r, c, n, r1, c1, r2, c2, regionCount;
bool map[MAX_ROWS][MAX_COLUMNS];
int regions[MAX_ROWS][MAX_COLUMNS];

void traverse(int r, int c, int value);

int main() {
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        if (regions[--r1][--c1] == regions[--r2][--c2] && regions[r1][c1] == 0) {
            regionCount++;
            traverse(r1, c1, map[r1][c1]);
        }
        if (regions[r1][c1] == regions[r2][c2]) {
            printf(map[r1][c1] ? "decimal\n" : "binary\n");
        } else {
            printf("neither\n");
        }
    }
}

void traverse(int i, int j, int value) {
    if (regions[i][j]) return;
    if (map[i][j] != value) return;
    regions[i][j] = regionCount;
    if (i > 0) traverse(i - 1, j, value);
    if (i < r - 1) traverse(i + 1, j, value);
    if (j > 0) traverse(i, j - 1, value);
    if (j < c - 1) traverse(i, j + 1, value);
}