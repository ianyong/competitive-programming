#include <cstdio>
using namespace std;

#define MAX_ROWS 50
#define MAX_COLUMNS 50

int R, C, ZR, ZC;
char matrix[MAX_ROWS][MAX_COLUMNS];

int main() {
    scanf("%d %d %d %d", &R, &C, &ZR, &ZC);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &matrix[i][j]);
        }
    }

    for (int i = 0; i < R * ZR; i++) {
        for (int j = 0; j < C * ZC; j++) {
            printf("%c", matrix[i / ZR][j / ZC]);
        }
        printf("\n");
    }
}