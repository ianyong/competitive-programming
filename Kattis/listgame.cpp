#include <cstdio>
#include <cmath>
using namespace std;

int X, numOfPrimeFactors;

int main() {
    scanf("%d", &X);
    while (!(X & 1)) {
        numOfPrimeFactors++;
        X >>= 1;
    }
    for (int i = 3; i <= sqrt(X); i += 2) {
        while (!(X % i)) {
            numOfPrimeFactors++;
            X /= i;
        }
    }
    if (X > 2) numOfPrimeFactors++;
    printf("%d", numOfPrimeFactors);
}