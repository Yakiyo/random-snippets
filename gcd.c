/**
* Get the HCF/GCD between
* the provided two numbers
* using euclid's method
 */

#include <stdio.h>

int getGcd(int a, int b) {
    int gcd, c;
    if (b == 0) {
        gcd = a;
    } else {
        while( b!= 0) {
            c = b;
            b = a % b;
            a = c;
        }
        gcd = a;
    }
    return gcd;
}
int main() {
    int x, y;
    printf("Please provide an integer: ");
    scanf("%d", x);
    printf("Please provide another integer: ");
    scanf("%d", y);
    if (x < y) {
        int z = x;
        x = y;
        y = z;
    }
    int gcd = getGcd(x, y);
    printf("The gcd of %d and %d is: %d", x, y, gcd);
    return 0;
}