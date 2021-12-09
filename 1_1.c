#include <stdio.h>
#include <stdlib.h>

#define NUM_LINES 2000

int main(){
    FILE *fp;
    int lines[2000];
    int value;
    int answer = 0;
    fp = fopen("input.txt", "r");

    for(int i = 0; i < NUM_LINES; i++){
        fscanf(fp, "%d", &value);
        lines[i] = value;
        if(i == 0){
            printf("%d (N/A - no previous measurement)", lines[i]);
        }
        else{
            if(lines[i] > lines[i-1]){
                answer++;
                printf("%d (increased)\n", lines[i]);
            }
            else{
                printf("%d (decreased)\n", lines[i]);
            }
        }
        
    }
    printf("the answer is %d", answer);


    return 0;
}