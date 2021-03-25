/*
 * Exercise 12 - Square Root
 *
 * Author: Ayman Makki
 * Date: 18.03.2021
 */

#include <stdio.h>
#include <math.h>

int mysqrt(double x, double *sqrtX) {
    if(x >= 0) {
        *sqrtX = sqrt(x);
        return 1;
    }
    return 0;
}

int main() {
    double x, result, *sqrtX;

    //sqrtX = &result;

    printf("x = ");
    scanf("%lf", &x);

    if(mysqrt(x, sqrtX) != 0)
        printf("sqrt(%lf) = %lf\n", x, *sqrtX);
    else
        printf("Invalid input.\n");

    return 0;
}
