#include <stdio.h>
#include <stdbool.h>

#define lenght 10
int i;

void Fib(int srcArr[]){
    srcArr[0] = 1;
    srcArr[1] = 1;
    // printf("%d\n%d\n", arr[0], arr[1]);
    for(i = 2; i < lenght; i++){
        srcArr[0] = i;
        srcArr[i] = srcArr[i-1] + srcArr[i-2];
        // printf("%d\n", arr[i]);  
    }
}

void offset(int srcArr1[], int srcArr2[]){
    int temp[lenght];
    temp[0] = 1;
    for(i = 1; i < lenght; i++){      // create signature series
        if(i%2 == 0){
            temp[i] = temp[i-1] + i+1;
        }
        else{
            temp[i] = temp[i-1] + i/2 +1;
        }
        // printf("%d\n", temp[i]);
    }
    bool sign = 0;                      // 0 = minus, 1 = plus
    int count = 0;
    int count1 = 0;
    int count2 = 0;
    for(i = 0; i < lenght; i++){     // sort sign entries
        if(count == 2){
            count = 0;
            sign = !sign;
        }
        if(sign){                       // append to plus (remove count1 to Improve!)
            srcArr1[count1] = temp[i];
            count1++;
        }
        else if(!sign){                 // append to minus (remove count2 to Improve!)
            srcArr2[count2] = temp[i];
            count2++;
        }
        count++;
    }
}

int main(){
    int src[lenght] = {0};
    int plus[lenght/2] = {[0 ... lenght/2-1] = 10*lenght};         // fill array with scalable
    int minus[lenght/2] = {[0 ... lenght/2-1] = 10*lenght};        // big number
    Fib(src);
    for(i = 0; i < 10; i++){
        printf("%d\n", src[i]);
    }
    offset(plus, minus);
    // for(i = 0; i < lenght/2; i++){
    //     printf("%d\n", plus[i]);
    // }
    // for(i = 0; i < lenght/2; i++){
    //     printf("%d\n", minus[i]);
    // }
    return 0;
}
