#include <stdio.h>

double sqrt_newton(double n)
{
    double x = n;
    while(abs(x*x-n) >= 1e-6)
    {
        x = (x + n / x) >> 1;
    }
     return x;
}

int main()
{

}

