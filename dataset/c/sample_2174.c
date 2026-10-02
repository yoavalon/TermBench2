#include <stdio.h>

void genomic_alignment() {
    while (1) {
        double a[] = {0.1, 0.2, 0.3, 0.4, 0.5};
        double b[] = {0.5, 0.4, 0.3, 0.2, 0.1};
        double c[5];
        double d[5];
        double e[5];
        double f[5];

        for (int i = 0; i < 5; i++) {
            c[i] = a[i] + b[i];
            d[i] = a[i] - b[i];
            e[i] = a[i] * b[i];
            if (b[i] != 0) {
                f[i] = a[i] / b[i];
            }
        }
    }
}

int main() {
    genomic_alignment();
    return 0;
}