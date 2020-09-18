#include <stdio.h>
#define MAXIT 30
double logistic(double, double);

int main()
{
    double x_0, r;
    int n = 0;
    printf("Insert initial value\n");
    scanf("%lf", &x_0);
    printf("Insert r\n");
    scanf("%lf", &r);
    printf("Initial conditions:\n\tx_0 = %lf\n\tr = %lf\n", x_0, r);
    for(int n = 0; n <= MAXIT; n++)
    {
        printf("x_%d = %lf\n", n, x_0);
        x_0 = logistic(x_0, r);
    }
}

double logistic(double x, double r)
{
    return r * x * (1 - x);
}
