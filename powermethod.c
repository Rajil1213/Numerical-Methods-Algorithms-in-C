#include <stdio.h>
#include <math.h>

int main()
{
    float a[4][4], x[4], b[4];
    int i, j, n;
    float greatest, eigen;
    printf("Enter the order: ");
    scanf("%d", &n);
    printf("Enter the matrix: \n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            printf("a %d %d: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    printf("Enter guess eigen vector: \n");
    for(i = 0; i < n; i++)
    {
        printf("x %d: ", i);
        scanf("%f", &x[i]);
    }
    do
    {
        for(i = 0; i < n; i++){
            b[i] = 0;
            for(j = 0; j < n; j++)
                b[i] = b[i] + a[i][j] * x[j];
        }
        greatest = fabs(b[0]);
        for(i = 1; i < n; i++){
            if(fabs(b[i]) > greatest)
                greatest = fabs(b[i]);
        }
        eigen = greatest;
        greatest = fabs(x[0] - b[0]/eigen);
        printf("Eigen = %.4f\n", eigen);
        for(i = 0; i < n; i++){
            if(fabs(x[i] - b[i]/eigen) > greatest)
                greatest = fabs(x[i] - b[i]/eigen);
            x[i] = b[i]/eigen;
        }
    }
    while(greatest > 0.00001);
    printf("Eigen value = %.3f", eigen);
    printf("\n Eigen vector: \n");
    for(i = 0; i < n; i++){
        printf("%.4f \n", x[i]);
    }
    return 0;
}
