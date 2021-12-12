#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LINES 1000
#define NUM_COLUMNS 12

int main(){

FILE *fp;
fp = fopen("input.txt", "r");
int gamma[NUM_COLUMNS];
int epsilon[NUM_COLUMNS];
char buffer[NUM_LINES][NUM_COLUMNS];
int idx;
int count = 0;

while(idx < NUM_LINES && fgets(buffer[idx], 20, fp) != NULL){
    idx++;
}

for(int i = 0; i < NUM_COLUMNS; i++){
    count = 0;
    for(int j = 0; j < NUM_LINES; j++){
        if(buffer[j][i] == '1'){
            count++;
        }
    }
    if(count >= NUM_LINES/2){
        gamma[i] = 1;
        epsilon[i] = 0;
    }
    else{
        gamma[i] = 0;
        epsilon[i] = 1;
    }
}
for(int i = 0; i < NUM_COLUMNS; i++){
    printf("%d", gamma[i]);
}
printf("\n");
for(int i = 0; i < NUM_COLUMNS; i++){
    printf("%d", epsilon[i]);
}

    return 0;
}