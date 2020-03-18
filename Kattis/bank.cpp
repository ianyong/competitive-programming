#include <cstdio>
using namespace std;

#define MAX_T 47

int N, T, c, t, queue[MAX_T], temp;

int main() {
    scanf("%d %d", &N, &T);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &c, &t);
        for (int j = t; j >= 0; j--) {
            if (!queue[j]) {
                queue[j] = c;
                break;
            } else if (c > queue[j]) {
                temp = queue[j];
                queue[j] = c;
                c = temp;
            }
        }
    }
    temp = 0;
    for (int i = 0; i < T; i++) {
        temp += queue[i];
    }
    printf("%d", temp);
}