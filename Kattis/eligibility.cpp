#include <cstdio>
using namespace std;

#define MAX_NAME_LENGTH 30

int numTestCases, studiesYear, birthYear, numCourses;
char name[MAX_NAME_LENGTH + 1];

int main() {
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        scanf("%s %d/%*d/%*d %d/%*d/%*d %d", name, &studiesYear, &birthYear, &numCourses);
        if (studiesYear >= 2010 || birthYear >= 1991) {
            printf("%s eligible\n", name);
        } else if (numCourses > 40) {
            printf("%s ineligible\n", name);
        } else {
            printf("%s coach petitions\n", name);
        }
    }
}
