#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ====== ToDo: Change src array to dynamic to prevent too large mem allocation ======

// #define lenght 2000             // check for primes up to this number
int i, j;                        // looping indices

void offset(int signs[], int lenght){
    int temp[lenght];
    temp[0] = 1;
    for(i = 1; i < lenght; i++){      // create pentagonal series (sign positions)
        if(i%2 == 0){
            temp[i] = temp[i-1] + i+1;    // increase by odd ascending int (3, 5, 7, ...)
        }
        else{
            temp[i] = temp[i-1] + i/2 +1;   // increase by ascending int (1, 2, 3, ...)
        }
    }
    // for(i = 0; i < lenght/2; i++){
    //     printf("%d\n", temp[i]);
    // }
    bool sign = 1;                      // 0 = minus, 1 = plus
    int count = 0;
    for(i = 0; i < lenght; i++){     // calculate sign positions
        if(temp[i] < lenght*2){
            if(count == 2){
            count = 0;
            sign = !sign;
        }
        if(sign){                       // append +1 to position
            signs[temp[i]-1] = 1;
        }
        else if(!sign){                 // append -1 to position
            signs[temp[i]-1] = -1;
        }
        count++;           
        }
    }
    // for(i = 0; i < 2*lenght; i++){
    //     printf("%d\n", signs[i]);
    // }
}

int main(int argc, char *argv[]){
    int lenght;
    lenght = atoi(argv[1]);
    int src[lenght];
    int signs[lenght*2];
    src[0] = 1;
    for(i = 1;i < lenght; i++){             // Fill signs array with 0
        signs[i] = 0;
        signs[i+lenght] = 0;
    }
    offset(signs, lenght);                         // Fill signs array

    int sum = 0;
    for(i = 1; i < lenght; i++){
        src[0] = i;
        for(j = 0; j < i; j++){
            sum += signs[j]*src[i-j-1];
            // if(signs[j]*src[i-j-1] != 0){
            //     printf("%d  ", signs[j]*src[i-j-1]);
            // }
        }
        // printf("= %d \n", sum);
        src[i] = sum;
        if(sum == i+1){                 // check for primes
            printf("%d\n", i);
        }
        sum = 0;
    }
    // for(i = 0; i < lenght; i++){
    //     printf("%d\n", src[i]);
    // }
    return 0;
}
