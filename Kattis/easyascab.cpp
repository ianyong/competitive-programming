#include <cstdio>
using namespace std;

#define MAX_L 26
#define MAX_STRING 1001
#define VISITED -1
#define VISITING -2

int L, N, inDegree[MAX_L], order[MAX_L], orderIndex = 0;
char c, str[MAX_STRING];
bool flag, adjMatrix[MAX_L][MAX_L];

void dfs(int i);

int main() {
    scanf("%c %d", &L, &N);
    L -= 'a' - 1;
    scanf("%s ", str);
    for (int i = 1; i < N; i++) {
        flag = true;
        for (int j = 0; ; j++) {
            if (scanf("%c", &c) == EOF || c == '\n') {
                if (flag) { // Current string is a substring of the previous
                    printf("IMPOSSIBLE");
                    return 0;
                }
                str[j] = '\0';
                break;
            }
            if (str[j] == '\0') flag = false;
            if (flag && c != str[j]) {
                adjMatrix[c - 'a'][str[j] - 'a'] = true;
                inDegree[str[j] - 'a']++;
                flag = false;
            }
            str[j] = c;
        }
    }
    flag = true;
    for (int i = 0; i < L; i++) {
        if (!inDegree[i]) dfs(i);
    }
    if (!flag || orderIndex < L) {
        printf("IMPOSSIBLE");
        return 0;
    }
    for (int i = 1; i < L; i++) {
        if (!adjMatrix[order[i]][order[i - 1]]) {
            printf("AMBIGUOUS");
            return 0;
        }
    }
    for (int i = 0; i < L; i++) {
        printf("%c", order[i] + 'a');
    }
}

void dfs(int i) {
    if (inDegree[i] == VISITED) return;
    if (inDegree[i] == VISITING) { // Cycle detected
        flag = false;
        return;
    }
    inDegree[i] = VISITING;
    for (int j = 0; j < L; j++) {
        if (adjMatrix[i][j]) dfs(j);
    }
    inDegree[i] = VISITED;
    order[orderIndex++] = i;
}