#include <iostream>
#include <string>
using namespace std;

#define MAX_N 100000

struct node {
    string data;
    struct node *next;
    struct node *end;
};

int N;
string str;
node *nodes[MAX_N];

void printString(node *currentNode);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        nodes[i] = new node{str, nullptr, nullptr};
    }

    int first = 0, second;
    for (int i = 0; i < N - 1; i++) {
        cin >> first >> second;
        first--;
        second--;
        if (nodes[first]->next == nullptr) {
            nodes[first]->next = nodes[second];
        } else {
            nodes[first]->end->next = nodes[second];
        }
        nodes[first]->end = nodes[second]->end == nullptr ? nodes[second] : nodes[second]->end;
    }

    printString(nodes[first]);
}

void printString(node *currentNode) {
    cout << currentNode->data;
    if (currentNode->next != nullptr) {
        printString(currentNode->next);
    }
}