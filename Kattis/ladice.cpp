#include <cstdio>
using namespace std;

#define MAX_DRAWERS 300001

int N, L, A, B, uf[MAX_DRAWERS];
bool taken[MAX_DRAWERS];

void unionSet(int a, int b);
int findSet(int i);

int main() {
    scanf("%d %d", &N, &L);
    for (int i = 1; i <= L; i++) uf[i] = i;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &A, &B);
        if (!taken[A]) {
            taken[A] = true;
            unionSet(A, B);
        } else if (!taken[B]) {
            taken[B] = true;
            unionSet(B, A);
        } else if (!taken[findSet(A)]) {
            taken[findSet(A)] = true;
            unionSet(A, B);
        } else if (!taken[findSet(B)]) {
            taken[findSet(B)] = true;
            unionSet(B, A);
        } else {
            printf("SMECE\n");
        }
    }
}

void unionSet(int a, int b) {
    printf("LADICA\n");
    uf[findSet(a)] = findSet(b);
}

int findSet(int i) {
    return uf[i] == i ? i : uf[i] = findSet(uf[i]);
}