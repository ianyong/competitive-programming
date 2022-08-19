#include <cstdio>
#include <cstring>
using namespace std;

#define MONTH_LENGTH 3

char month[MONTH_LENGTH + 1];
int date;

int main() {
    scanf("%s %d", month, &date);
    if (strcmp(month, "OCT") == 0 && date == 31 || strcmp(month, "DEC") == 0 && date == 25) {
        printf("yup\n");
        return 0;
    }
    printf("nope\n");
}
