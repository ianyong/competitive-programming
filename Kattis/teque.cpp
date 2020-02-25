#include <cstdio>
#include <deque>
#include <cstring>
using namespace std;

#define STRING_MAX 12

int N, value;
char operation[STRING_MAX];
deque<int> frontDeque, backDeque;

void balanceDeques();

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s %d", operation, &value);

        if (strcmp(operation, "get") == 0) {
            if (value < frontDeque.size()) {
                printf("%d\n", frontDeque[value]);
            } else {
                printf("%d\n", backDeque[value - frontDeque.size()]);
            }
        } else {
            if (strcmp(operation, "push_back") == 0) {
                backDeque.push_back(value);
            } else if (strcmp(operation, "push_front") == 0) {
                frontDeque.push_front(value);
            } else {
                backDeque.push_front(value);
            }
            balanceDeques();
        }
    }
}

void balanceDeques() {
    if (backDeque.size() > frontDeque.size()) {
        frontDeque.push_back(backDeque.front());
        backDeque.pop_front();
    } else if (frontDeque.size() > backDeque.size() + 1) {
        backDeque.push_front(frontDeque.back());
        frontDeque.pop_back();
    }
}