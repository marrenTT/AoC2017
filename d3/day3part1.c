#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main (void){
    int target;
    int sum = 0;
    char *line = NULL;
    char *rest;
    char *token;
    size_t size;

    /* keep track of movements */
    int x, y, xs, ys, ampli, temp; 
    


    while (getline(&line, &size, stdin) != -1){
        line[strcspn(line, "\r\n")] = 0;
        target = atoi(line);
        
        x = y = xs = ampli = 0;
        ys = -1;

        for(;;){
            ampli += 1;
            if(target == ampli){
                sum = abs(x) + abs(y);
                printf("%d\n", sum);
                free(line); // OBS!
                line = NULL;
                return sum;
            }

            if((x == y)|| ((x < 0) && (x == -y)) || ((x > 0) && (x == 1-y))){
                temp = xs; 
                xs = -ys;
                ys = temp;
            }
            x += xs;
            y += ys;
        }
    }
    
    return 0;
}