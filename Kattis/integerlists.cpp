#include <cstdio>
#include <stack>
using namespace std;

int m, n, dropFront, dropBack, d;
bool reversed;
char c;
stack<int> s;

int main() {
    scanf("%d ", &m);
    for (int i = 0; i < m; i++) {
        dropFront = dropBack = 0;
        reversed = false;
        while ((c = getchar()) != '\n') {
            switch (c) {
                case 'D':
                    reversed ? dropBack++ : dropFront++;
                    break;
                case 'R':
                    reversed ^= 1;
                    break;
            }
        }
        scanf("%d [", &n);
        if (dropBack + dropFront >= n) {
            scanf("%*s ");
            if (dropBack + dropFront == n)
                printf("[]\n");
            else
                printf("error\n");
            continue;
        }
        printf("[");
        if (reversed) {
            for (int j = 0; j < n; j++) {
                scanf("%d,", &d);
                if (j >= dropFront && j < n - dropBack)
                    s.push(d);
            }
            while (!s.empty()) {
                printf("%d", s.top());
                s.pop();
                printf(s.empty() ? "]\n" : ",");
            }
        } else {
            for (int j = 0; j < n; j++) {
                scanf("%d,", &d);
                if (j >= dropFront && j < n - dropBack) {
                    printf("%d", d);
                    printf(j == n - dropBack - 1 ? "]\n" : ",");
                }
            }
        }
        scanf("%*c ");
    }
}