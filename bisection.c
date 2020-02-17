#include <stdio.h>
#include <math.h>

double f(double x)
{
    return (sin(x) - cos(x));
}

int main()
{
    double a, b, c, tmp;
    printf("Enter bracket, a b\n");
    scanf("%lf %lf", &a, &b);
    if(f(a) * f(b) > 0)
    {
        printf("No solution exits in this bracket\n");
        return 1;
    }
    if(f(a) > 0)
    {
        tmp=a;
        a = b;
        b = tmp;
    }
    c = (a + b)/2;
    while(fabs(f(c)) > 0.0001)
    {
        if(f(c) < 0)
            a = c;
        else
            b = c;
        c = (a + b)/2;
    }
    printf("The solution to your problem is %.3lf", c);
    return 0;
}
