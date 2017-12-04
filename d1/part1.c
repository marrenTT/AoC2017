#include <stdio.h>
#include <ctype.h> // For mapping characters


int main (void){
    int current;
    int first;
    int prev;
    int sum = 0; 

    first = current = getchar();

    while(current != EOF){ //EOF - End Of File
        if(isdigit(current)){
            if(current == prev) {
                sum += current-'0'; // To make it numeric
            }
            prev = current;    
        }
        current = getchar();
    }

    // Check if the first and last are the same
    if(first != EOF && prev == first){
        sum += first-'0';
    }

    printf("%d\n", sum);

    return 0;
}