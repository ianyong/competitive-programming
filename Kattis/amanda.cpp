#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define MAX_AIRPORTS 200001

enum Colour{none, hasLounge, noLounge, red, black};
int n, m, a, b, c, numOfLounges = 0;
Colour airport[MAX_AIRPORTS];
vector<int> adjList[MAX_AIRPORTS];
vector<pair<int, int> > oneQueries;
queue<int> frontier, nextFrontier;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        switch (c) {
            case 0:
                if (airport[a] == hasLounge || airport[b] == hasLounge) {
                    printf("impossible");
                    return 0;
                }
                airport[a] = noLounge;
                airport[b] = noLounge;
                break;
            case 1:
                adjList[a].push_back(b);
                adjList[b].push_back(a);
                oneQueries.push_back(make_pair(a, b));
                break;
            case 2:
                if (airport[a] == noLounge || airport[b] == noLounge) {
                    printf("impossible");
                    return 0;
                }
                if (airport[a] != hasLounge) numOfLounges++;
                if (airport[b] != hasLounge) numOfLounges++;
                airport[a] = hasLounge;
                airport[b] = hasLounge;
        }
    }
    for (pair<int, int> p : oneQueries) {
        if (airport[p.first] == airport[p.second] && airport[p.first] != none) {
            printf("impossible");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (airport[i] == none) {
            Colour loungeColour = none, currentColour = red;
            int numOfRed = 1, numOfBlack = 0;
            airport[i] = currentColour;
            for (int e : adjList[i]) {
                nextFrontier.push(e);
            }
            while(!nextFrontier.empty()) {
                currentColour = currentColour == red ? black : red;
                swap(frontier, nextFrontier);
                while (!frontier.empty()) {
                    int e = frontier.front();
                    frontier.pop();
                    switch (airport[e]) {
                        case none:
                            airport[e] = currentColour;
                            if (currentColour == red) numOfRed++;
                            else numOfBlack++;
                            for (int f : adjList[e]) {
                                nextFrontier.push(f);
                            }
                            break;
                        case hasLounge:
                            if (loungeColour != none) {
                                if (currentColour != loungeColour) {
                                    printf("impossible");
                                    return 0;
                                }
                            } else {
                                loungeColour = currentColour;
                            }
                            break;
                        case noLounge:
                            if (loungeColour != none) {
                                if (currentColour == loungeColour) {
                                    printf("impossible");
                                    return 0;
                                }
                            } else {
                                loungeColour = currentColour == red ? black : red;
                            }
                            break;
                        case red:
                        case black:
                            if (currentColour != airport[e]) {
                                printf("impossible");
                                return 0;
                            }
                    }
                }
            }
            switch (loungeColour) {
                case none:
                    numOfLounges += min(numOfRed, numOfBlack);
                    break;
                case red:
                    numOfLounges += numOfRed;
                    break;
                case black:
                    numOfLounges += numOfBlack;
            }
        }
    }
    printf("%d", numOfLounges);
}