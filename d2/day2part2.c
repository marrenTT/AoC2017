#pragma clang diagnostic ignored "-Wreserved-id-macro" // Ignore the diagnostic message

#define _WITH_GETLINE
#define LEN(a) (int)(sizeof(a)/sizeof(*a))

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main (void){
    int sum = 0;
    char *index = NULL;
    char *rest;
    char *token;
    size_t size;
    int num[16], t, val, i, j;


    while (getline(&index, &size, stdin) != -1){
        rest = index;
        t = 0;
        
        while(t < LEN(num) && (token = strsep(&rest, " \t"))){
            num[t++] = (int)strtol(token, NULL, 10);     
        }

        val = 0;
        for(i=0; !val && i < t; i++){
            for(j= i +1; !val && j < t; j++){
                if(!(num[i]%num[j]))
                    val = num[i]/num[j];
                if(!(num[j]%num[i]))
                    val = num[j]/num[i];
            }   

        }

        sum += val;
        free(index); // OBS!
        index = NULL;
    }
    
    printf("%d\n", sum);
    return 0;
}