#include <cstdio>
#include <algorithm>
using namespace std;

int uglyNum[1500] = {1}, factorCount[3] = {};
const int factor[3] = {2, 3, 5};

int main(){
    for(int i = 1; i < 1500; i++){
        for(int j = 0; j < 3; j++){
            while(uglyNum[factorCount[j]] * factor[j] <= uglyNum[i - 1]){
                factorCount[j]++;
            }
        }
        uglyNum[i] = uglyNum[factorCount[0]] * factor[0];
        for(int j = 1; j < 3; j++){
            uglyNum[i] = min(uglyNum[i], uglyNum[factorCount[j]] * factor[j]);
        }
    }
    printf("The 1500'th ugly number is %d.\n", uglyNum[1499]);
}
