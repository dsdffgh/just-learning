
#include <stdio.h>

// 定义计算平方根的函数
double sqrt_taylor(double x) {
    if (x == 0) return 0;

    if (x < 0) {
        printf("Error: Negative input for square root.\n");
        return -1;
    }

    double y = x - 1;
    double sqrt_x = 1;
    double term = 1;
    int n = 1;

    for (int i = 1; i <= 20; i++) {
        term *= y / n;
        sqrt_x += (n % 2 == 0 ? -1 : 1) * term / (2 * n);
        n++;
    }

    return sqrt_x;
}

int main() {
    double x;
    printf("Enter a number to compute its square root: ");
    scanf("%lf", &x);

    double result = sqrt_taylor(x);
    if (result != -1) {
        printf("The square root of %.5f is approximately %.5f\n", x, result);
    }

    return 0;
}
