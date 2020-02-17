#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float x[10], y[10], a, b, A;
    float sumx = 0, sumy = 0, sumxx = 0, sumxy = 0;
    printf("Enter the no. of data pairs: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("x%d= ", i);
        scanf("%f", &x[i]);
        printf("y%d= ", i);
        scanf("%f", &y[i]);
        sumx = sumx + x[i];
        sumy = sumy + log(y[i]);
        sumxx = sumxx + x[i] * x[i];
        sumxy = sumxy + x[i] * log(y[i]);
    }
    b = (sumx * sumy - n * sumxy) / (sumx * sumx - n * sumxx);
    A = (sumy - b * sumx) / n;
    a = exp(A);
    printf("The exponential curve is : y = %.3f exp (%.3f x)", a, b);
    return 0;

}
