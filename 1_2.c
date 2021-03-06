#include <stdio.h>
#include <stdlib.h>

#define NUM_LINES 2000

int main(){
    FILE *fp;
    int lines[NUM_LINES];
    int sum[NUM_LINES/2];
    int value;
    int answer = 0;
    fp = fopen("input.txt", "r");

    for(int i = 0; i < NUM_LINES; i++){
        fscanf(fp, "%d", &value);
        lines[i] = value;
        sum[i] = lines [i] + lines[i-1] + lines[i-2];
        printf("%d ", lines[i-2]);
        printf("%d ", lines[i-1]);
        printf("%d ", lines[i]);
        printf("sum: %d    ", sum[i]);
        if(i <= 2){
            printf("%d (N/A - no previous sum)\n", lines[i]);
        }
        else{
            if(sum[i] > sum[i-1]){
                answer++;
                printf("%d (increased)\n", sum[i]);
            }
            else if(sum[i] == sum[i-1]){
                printf("%d (no change)\n", sum[i]);
            }
            else{
                printf("%d (decreased)\n", sum[i]);
            }
        }
        
    }
    printf("the answer is %d", answer);


    return 0;
}