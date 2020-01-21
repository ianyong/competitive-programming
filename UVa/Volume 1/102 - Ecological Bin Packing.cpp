#include <cstdio>
#include <string>
using namespace std;

void updateMinBottleMovements(string);

int b[3], g[3], c[3], minBottleMovements, bottleMovements;
string binOrder;

int main() {
    while (scanf("%d%d%d%d%d%d%d%d%d", &b[0], &g[0], &c[0], &b[1], &g[1], &c[1], &b[2], &g[2], &c[2]) != EOF) {
        // BCG
        minBottleMovements = g[0] + c[0] + b[1] + g[1] + b[2] + c[2];
        binOrder = "BCG";
        // BGC
        bottleMovements = g[0] + c[0] + b[1] + c[1] + b[2] + g[2];
        updateMinBottleMovements("BGC");
        // CBG
        bottleMovements = b[0] + g[0] + g[1] + c[1] + b[2] + c[2];
        updateMinBottleMovements("CBG");
        // CGB
        bottleMovements = b[0] + g[0] + b[1] + c[1] + g[2] + c[2];
        updateMinBottleMovements("CGB");
        // GBC
        bottleMovements = b[0] + c[0] + g[1] + c[1] + b[2] + g[2];
        updateMinBottleMovements("GBC");
        // GCB
        bottleMovements = b[0] + c[0] + b[1] + g[1] + g[2] + c[2];
        updateMinBottleMovements("GCB");
        printf("%s %d\n", binOrder.c_str(), minBottleMovements);
    }
}

void updateMinBottleMovements(string str) {
    if (bottleMovements < minBottleMovements) {
        minBottleMovements = bottleMovements;
        binOrder = str;
    }
}
