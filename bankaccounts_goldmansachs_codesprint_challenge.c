#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char* feeOrUpfront(int n, float k, int x, float d, float* p) {
   float sum=0,per = 0,max= 0;
    for (int i =0;i<n;i++)
    {
        per= (p[i]*x)/100;
        if (per > (k)) max  = per;
        else max = k;
        sum = sum + max;
        //printf("%f %f",per,max);
    }
    //printf("%f %f\n",sum,(float)d);
    if (sum <= d) return "fee";
        else return "upfront";
}

int main() {
    int q; 
    scanf("%i", &q);
    for(int a0 = 0; a0 < q; a0++){
        int n; 
        float k; 
        int x; 
        float d; 
        scanf("%i %f %i %f", &n, &k, &x, &d);
        float *p = malloc(sizeof(float) * n);
        for (int p_i = 0; p_i < n; p_i++) {
            scanf("%f",&p[p_i]);
        }
        int result_size;
        char* result = feeOrUpfront(n, k, x, d, p);
        printf("%s\n", result);
    }
    return 0;
}
