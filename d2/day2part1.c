#pragma clang diagnostic ignored "-Wreserved-id-macro" // Ignore the diagnostic message

#define _WITH_GETLINE

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main (void){
    int sum = 0;
    int min, max, n;
    char *index = NULL;
    char *rest;
    char *token;
    size_t size;

    while (getline(&index, &size, stdin) != -1){
        rest = index;
        min = INT_MAX; 
        max = INT_MIN;
        
        while((token = strsep(&rest, " \t"))){
            n = (int)strtol(token, NULL, 10);
            if (n < min) // the '?' operator   
                min = n;
            if (n > max)
                max = n;
        }

        sum += max - min;
        free(index); // OBS!
        index = NULL;
    }
    
    printf("%d\n", sum);
    return 0;
}