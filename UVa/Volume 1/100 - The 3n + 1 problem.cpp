#include <cstdio>
#include <algorithm>
using namespace std;

int i, j, maxCycleLength, cycleLength;

int main(){
	while(scanf("%d%d", &i, &j) != EOF){
		maxCycleLength = 0;
		printf("%d %d ", i, j);
		if(i > j){
			swap(i, j);
		}
		for(; i <= j; i++){
			cycleLength = 1;
			for(int currentNum = i; currentNum != 1; cycleLength++){
				if(currentNum & 1){ // Odd
					currentNum = currentNum * 3 + 1;
				}else{ // Even
					currentNum >>= 1;
				}
			}
			maxCycleLength = max(maxCycleLength, cycleLength);
		}
		printf("%d\n", maxCycleLength);
	}
}