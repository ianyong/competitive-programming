#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int N, E, G, X;
string command;
map<long, priority_queue<long> > quests;

long query(long remainingEnergy);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == "add") {
            cin >> E >> G;
            if (quests.find(E) == quests.end()) {
                quests.insert({E, priority_queue<long>()});
            }
            quests[E].push(G);
        } else {
            cin >> X;
            cout << query(X) << endl;
        }
    }
}

long query(long remainingEnergy) {
    map<long, priority_queue<long> >::iterator it = quests.upper_bound(remainingEnergy);
    if (it == quests.begin()) {
        return 0L;
    }
    it--;
    long value = it->second.top();
    it->second.pop();
    if (!it->second.size()) {
        quests.erase(it);
    }
    return value + query(remainingEnergy - it->first);
}