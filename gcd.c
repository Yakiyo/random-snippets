/**
* Get the HCF/GCD between
* the provided two numbers
* using euclid's method
 */

#include <stdio.h>

int main() {
    int a, b;
    printf("Please provide an integer: ");
    scanf("%d", &a);
    printf("Please provide another integer: ");
    scanf("%d", &b);
    if (a < b) {
        int z = a;
        a = b;
        b = z;
    }
    int x = a, y = b;
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
    printf("The gcd of %d and %d is: %d", x, y, gcd);
    return 0;
}