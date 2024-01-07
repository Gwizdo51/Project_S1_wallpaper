#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float a = .1, b = .3, left_rounded, right_rounded;
    if (b == a * 3) {
        printf("0.1 + 0.1 + 0.1 == 0.3\n");
    }
    else {
        printf("0.1 + 0.1 + 0.1 != 0.3\n");
    }
    left_rounded = roundf(b * 100) / 100;
    right_rounded = roundf((3 * a) * 100) / 100;
    if (left_rounded == right_rounded) {
        printf("round(0.1 + 0.1 + 0.1, 2) == round(0.3, 2)\n");
    }
    else {
        printf("round(0.1 + 0.1 + 0.1, 2) != round(0.3, 2)\n");
    }
    printf("b == %f, 3 * a == %f\n", b, a * 3);
}
