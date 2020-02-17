#include <stdio.h>


int main()
{
    int n, i;
    float sx, sy, sxx, sxy;
    float x[10], y[10];
    float a, b;
    sx = 0;
    sy = 0;
    sxx = 0;
    sxy = 0;
    printf("How many pairs?\n");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        printf("Enter pair #%d: x y\n", i+1);
        scanf("%f %f", &x[i], &y[i]);
        sx = sx + x[i];
        sy = sy + y[i];
        sxx = sxx + x[i] * x[i];
        sxy = sxy + x[i] * y[i];
    }
    a = (sx * sy - n * sxy)/(sx * sx - n * sxx);
    b = (sy - a * sx)/ n;
    printf("The best fit line is y = %.3f x + %.3f", a, b);
    return 0;
}
