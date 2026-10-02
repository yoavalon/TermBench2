#include <stdio.h>

typedef struct {
    double a;
    double b;
    double c;
} Result;

Result simulate(double a, double b, double c) {
    Result res;
    while (1) {
        res.a = b;
        res.b = c;
        res.c = (a + b + c) / 3.0;
        a = res.a;
        b = res.b;
        c = res.c;
        return res;
    }
}

void main() {
    double a = 1.0, b = 2.0, c = 3.0;
    while (1) {
        Result res = simulate(a, b, c);
        printf("%.5f, %.5f, %.5f\n", res.a, res.b, res.c);
        a = res.a;
        b = res.b;
        c = res.c;
    }
}