#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x) - sin(x) - 2;
}

float df(float x)
{
    return exp(x) - cos(x);
}

int main()
{
    float x0, tolerance, M;
    int n = 0;
    printf("Enter the initial guess, x0 ");
    scanf("%f", &x0);
    tolerance = 0.0001;
    M = 1000;
    do
    {
        if(fabs(df(x0)) < tolerance)
        {
            printf("Maxima/Minima error\n");
            return 1;
        }
        x0 = x0 - (f(x0)/ df(x0));
        n++;
        if(n > M)
        {
            printf("Too many iterations!");
            return 1;
        }
    }while(fabs(f(x0)) > tolerance);
    printf("The solution is x = %.3f", x0);
    return 0;

}
