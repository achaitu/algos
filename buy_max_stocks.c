#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

long int temp;
long int count = 0;
long int i,j = 0;
long int k,past;
int n; 


long int buyMaximumProducts(int n, long int k, int* a) {
    while( k> 0 && i<n)
    { 
            past = k;
            k = k -(i+1)* a[i];
            
            i +=1;
        //printf("%ld ",k);
    }
    temp = past / (long int)a[i-1];
    //printf("%ld ",temp);
    count = (i*(i-1))/2+temp;
    
    

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
