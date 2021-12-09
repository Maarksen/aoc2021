#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LINES 1000

int main(){

    int vertical = 0;
    int horizontal = 0;
    int answer = 0;
    int add;

    FILE *fp;
    fp = fopen("input.txt", "r");
    char buffer[NUM_LINES];
    

    while(fgets(buffer, 100, fp)){
        char *command = strtok(buffer, " ");
        char *number = strtok(NULL, " ");

        if(strcmp(command, "forward") == 0){
            add = atoi(number);
            horizontal = horizontal + add;
        }
        else if(strcmp(command, "up") == 0){
            add = atoi(number);
            vertical = vertical - add;
        }
        else{
            add = atoi(number);
            vertical = vertical + add;
        }
    }
    printf("horizontal is :%d\n", horizontal);
    printf("vertiacal is : %d\n", vertical);

    answer = vertical *horizontal;

    printf("%d\n", answer);

    return 0;
}