#include <cstdio>
#include <algorithm>
using namespace std;

int N, mCounter, pos, j;
bool regions[100] = {};

int main() {
    while (true) {
        scanf("%d", &N);
        if (!N) {
            break;
        }
        for (int i = 1; ; i++) {
            fill(regions + 1, regions + N, true);
            pos = 0;
            for (j = 1; j < N; j++) {
                mCounter = 0;
                while (mCounter < i) {
                    ++pos %= N;
                    if (regions[pos]) {
                        mCounter++;
                    }
                }
                if (pos == 12) {
                    break;
                }
                regions[pos] = false;
            }
            if (j == N - 1) {
                printf("%d\n", i);
                break;
            }
        }
    }
}