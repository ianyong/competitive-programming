#include <cstdio>
using namespace std;

int N, M, leftovers;

int main() {
    scanf("%d %d", &N, &M);
    leftovers = M - N;
    if (leftovers == 1) {
        printf("Dr. Chaz will have 1 piece of chicken left over!\n");
    } else if (leftovers == -1) {
        printf("Dr. Chaz needs 1 more piece of chicken!\n");
    } else if (leftovers > 0) {
        printf("Dr. Chaz will have %d pieces of chicken left over!\n", leftovers);
    } else {
        printf("Dr. Chaz needs %d more pieces of chicken!\n", -leftovers);
    }
}
