#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int temp;
long int count = 0;
long int i = 0;
long int k;
int n; 

void repeat(long int temp, long int k, int*a){
    
        printf("%d %d %d",k,temp,a[i]);
            if (k> 0)
            {
                temp = temp + temp/2 +1;
            }
            else {
                temp = temp - temp/2;
            }
    
}

long int buyMaximumProducts(int n, long int k, int* a) {
    while( k> 0 && i<n)
    {
            temp = (i+1) /2; 
            k = k -(temp+1)* a[i];
            repeat(temp,k,a);
            if(temp == i){    
                i +=1;
                printf("\n yes\n");
            }
            else{
                repeat(temp,k,a);
            }
    }
    count = (i*i+1)/2+temp;
    return count;
}


    

    
int main() {
    scanf("%i", &n);
    int *arr = malloc(sizeof(int) * n);
    for (int arr_i = 0; arr_i < n; arr_i++) {
    	scanf("%i",&arr[arr_i]);
    }
     
    scanf("%li", &k);
    long int result = buyMaximumProducts(n, k, arr);
    printf("%ld\n", result);
    return 0;
}
