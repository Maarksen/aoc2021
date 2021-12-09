#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_LINES 1000

int main(){

    long long aim = 0;
    long long vertical = 0;
    long long horizontal = 0;
    long long answer = 0;
    long long add;

    FILE *fp;
    fp = fopen("input.txt", "r");
    char buffer[NUM_LINES];
    

    while(fgets(buffer, 100, fp)){
        char *command = strtok(buffer, " ");
        char *number = strtok(NULL, " ");

        if(strcmp(command, "forward") == 0){
            add = atoi(number);
            horizontal = horizontal + add;
            vertical = vertical + (add * aim);
        }
        else if(strcmp(command, "up") == 0){
            add = atoi(number);
            aim = aim - add;
        }
        else{
            add = atoi(number);
            aim = aim + add;
        }
    }
    printf("horizontal is :%d\n", horizontal);
    printf("vertiacal is : %d\n", vertical);
    printf("aim is: %d\n", aim);

    answer = vertical * horizontal;

    printf("%d", answer);

    return 0;
}