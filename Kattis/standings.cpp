#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, place;
vector<int> standings;
unsigned long long badness;

int main() {
    scanf("%d", &T);
    while (T--) {
        standings.clear();
        badness = 0;
        scanf("%d", &N);
        while (N--) {
            scanf("%*s %d", &place);
            standings.push_back(place);
        }
        sort(standings.begin(), standings.end());
        for (int i = 1; i <= standings.size(); i++)
            badness += abs(standings[i - 1] - i);
        printf("%llu\n", badness);
    }
}