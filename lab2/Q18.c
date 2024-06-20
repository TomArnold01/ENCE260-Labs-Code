#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void printRoots(float a, float b, float c)
{
    double discriminant = b*b - 4*a*c;
    if (a == 0) {
        printf("Not a quadratic\n");
    }
    else if(discriminant < 0) {
        printf("Imaginary roots\n");
    }
    else{
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);

        if (root1 < root2) {
            printf("Roots are %.4f and %.4f\n", root1, root2);
        } else {
            printf("Roots are %.4f and %.4f\n", root2, root1);
            }
        }
}

int main(void) {
    printRoots(4, 1, -3);
}

