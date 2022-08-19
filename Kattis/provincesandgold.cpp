#include <cstdio>
using namespace std;

#define PROVINCE_COST 8
#define DUCHY_COST 5
#define ESTATE_COST 2

#define GOLD_COST 6
#define SILVER_COST 3
#define COPPER_COST 0

int G, S, C, buyingPower;

int main() {
    scanf("%d %d %d", &G, &S, &C);
    buyingPower = G * 3 + S * 2 + C;
    if (buyingPower >= PROVINCE_COST) {
        printf("Province");
    } else if (buyingPower >= DUCHY_COST) {
        printf("Duchy");
    } else if (buyingPower >= ESTATE_COST) {
        printf("Estate");
    }
    if (buyingPower >= ESTATE_COST) {
        printf(" or ");
    }
    if (buyingPower >= GOLD_COST) {
        printf("Gold");
    } else if (buyingPower >= SILVER_COST) {
        printf("Silver");
    } else {
        printf("Copper");
    }
    printf("\n");
}
