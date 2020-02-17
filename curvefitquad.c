#include <stdio.h>
#include <math.h>

int main()
{
    float x[10], y[10],b, c, a[10][10],t ;
    int i, j, k, d, n;
    printf("Enter the no. of data \n");
    scanf("%d", &n);
    printf("Enter the value of degree \n");
    scanf("%d", &d);
    printf("Enter data: x y \n");
    for(i = 0; i < n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }
    for(i = 0; i < d + 1; i++)
    {
        for(j = 0; j < d + 1; j++)
        {
            a[i][j] = 0;
            for(k = 0; k < n; k++)
            {
                a[i][j] = a[i][j] + pow(x[k], i + j);
            }
        }
    }

    for(i = 0; i < d+1; i++)
    {
        a[i][d + 1] = 0;
        for(j = 0; j < n; j++)
        {
            a[i][d + 1] = a[i][d + 1] + pow(x[j], i) * y[j];
        }
    }

    for(j = 0; j < d+1; j++)
    {
        for(i = 0; i < d+1; i++)
        {
            if(i != j)
            {
                t = a[i][j]/a[j][j];
                for(k = 0; k < d + 2; k++)
                {
                    a[i][k] = a[i][k] - t * a[j][k];
                }
            }
        }
    }

    for(i = 0; i < d + 1; i++)
    {
        a[i][d + 1] = a[i][d + 1]/a[i][i];
        printf("Coefficient of x ^ %d = %.2f\n", i, a[i][d + 1]);
    }

    return 0;
}
