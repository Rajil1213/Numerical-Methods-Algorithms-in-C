#include <stdio.h>
#include <math.h>

float f(float x)
{
    return sin(x) - cos(x);
}

int main()
{
    float a, b, c, tolerance, M;
    int n = 0;
    tolerance = 0.0001;
    M = 1000;
    printf("Enter the end points of the bracket: a b ");
    scanf("%f %f", &a, &b);
    do
    {
        if(fabs(f(b) - f(a)) < tolerance)
        {
            printf("Error detected");
            return 1;
        }
        c = (a*f(b) - b*f(a))/ (f(b) - f(a));
        a = b;
        b = c;
        n++;
        if(n > M)
        {
            printf("Too many iterations");
            return 1;
        }
    }while(fabs(f(c)) > tolerance);
    printf("The solution is: x = %.3f", c);
    return 0;
}
