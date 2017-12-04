#pragma clang diagnostic ignored "-Wreserved-id-macro" // Ignore the diagnostic message

#define _WITH_GETLINE

#include <stdio.h> 
#include <stdlib.h>

int main (void){
    char *pivot = NULL; 
    size_t lsize;
    int length; 
    int sum = 0;
    int t;          // NTS, declare first 

    if((length = (int)getline(&pivot, &lsize, stdin)) == EOF){
        perror("Error while processing input length.");
        return(-1);
    }

    for(t=0; t<length/2; t++)
        if(pivot[t] == pivot[length/2 + t])
            sum += pivot[t]-'0';

    

    printf("%d\n", sum*2);
    return 0;
}