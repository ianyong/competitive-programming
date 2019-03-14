#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

#define MAX_BLOCKS 25

void moveOnto(int, int);
void moveOver(int, int);
void pileOnto(int, int);
void pileOver(int, int);
void printBlocks(int);

stack<int> s[MAX_BLOCKS], temp;
int blockPositions[MAX_BLOCKS];

int main(){
	int n, a, b;
	char com1[5], com2[5];
	scanf("%d", &n);

	// Initialise stacks and block positions
	for(int i = 0; i < n; i++){
		s[i].push(i);
		blockPositions[i] = i;
	}

	while(true){
		scanf("%s%d%s%d", com1, &a, com2, &b);
		if(!strcmp(com1, "quit")){
			printBlocks(n);
			break;
		}else if(a == b || blockPositions[a] == blockPositions[b]){ // Invalid command || blocks are on the same stack
			continue;
		}else if(!strcmp(com1, "move")){
			if(!strcmp(com2, "onto")){ // move a onto b
				moveOnto(a, b);
			}else{ // move a over b
				moveOver(a, b);
			}
		}else{
			if(!strcmp(com2, "onto")){ // pile a onto b
				pileOnto(a, b);
			}else{ // pile a over b
				pileOver(a, b);
			}
		}
	}
}

void returnBlocksAbove(int block){
	while(s[blockPositions[block]].top() != block){
		int i = s[blockPositions[block]].top();
		blockPositions[i] = i;
		s[i].push(i);
		s[blockPositions[block]].pop();
	}
}

void moveBlock(int from, int to){
	s[blockPositions[to]].push(from);
	s[blockPositions[from]].pop();
	blockPositions[from] = blockPositions[to];
}

void moveStack(int from, int to){
	while(s[blockPositions[from]].top() != from){
		temp.push(s[blockPositions[from]].top());
		s[blockPositions[from]].pop();
	}
	moveBlock(from, to);
	while(!temp.empty()){
		s[blockPositions[to]].push(temp.top());
		blockPositions[temp.top()] = blockPositions[to];
		temp.pop();
	}
}

void moveOnto(int a, int b){
	returnBlocksAbove(a);
	returnBlocksAbove(b);
	moveBlock(a, b);
}

void moveOver(int a, int b){
	returnBlocksAbove(a);
	moveBlock(a, b);
}

void pileOnto(int a, int b){
	returnBlocksAbove(b);
	moveStack(a, b);
}

void pileOver(int a, int b){
	moveStack(a, b);
}

void printBlocks(int n){
	for(int i = 0; i < n; i++){
		printf("%d:", i);
		while(!s[i].empty()){
			temp.push(s[i].top());
			s[i].pop();
		}
		while(!temp.empty()){
			printf(" %d", temp.top());
			temp.pop();
		}
		printf("\n");
	}
}