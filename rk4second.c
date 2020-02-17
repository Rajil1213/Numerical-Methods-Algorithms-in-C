#include <stdio.h>
#include <math.h>

float f(float x, float y, float z)
{
    return -(x * z - y);
}

int main()
{
    float x, x0, y0, z0, h, i;
    float k1, k2, k3, k4, k;
    float l1, l2, l3, l4, l;
    printf("Enter the intial conditions: x0 y0 z0: \n");
    scanf("%f %f %f", &x0, &y0, &z0);
    x = x0;
    printf("Enter the step size: h: \n");
    scanf("%f", &h);
    printf("Enter the value of x where y, z is to be evaluated: x \n");
    scanf("%f", &x);
    printf("Solution: \n \n");
    for(i = 0.0;  fabs(x - i) > 0.0001; i+=h)
    {
        k1 = h * z0;
        l1 = h*f(x0, y0, z0);
        k2 = h * (z0 + 0.5 * l1);
        l2 = h*f(x0 + 0.5 * h, y0 + 0.5 * k1, z0 + 0.5 * l1);
        k3 = h * (z0 + 0.5 * l2);
        l3 = h*f(x0 + 0.5 *h, y0 + 0.5 * k2, z0 + 0.5 * l2);
        k4 = h * (z0 + l3);
        l4 = h*f(x0 + h, y0 + k3, z0 + l3);
        k = (k1 + 2*k2 + 2*k3 + k4)/6.0;
        l = (l1 + 2*l2 + 2*l3 + l4)/6.0;
        x0 +=h;
        y0 +=k;
        z0 +=l;
        printf("y(%.2f)\t \t = %.4f\n", x, y0);
        printf("z = y'(%.2f) \t = %.4f\n \n", x, z0);
    }
    return 0;

}
