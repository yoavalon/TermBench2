#include <stdio.h>
#include <math.h>

void func(double a, double b) {
    double c = a / b;
    while (1) {
        double d = c * 1000000;
        int e = (int)d;
        double f = d - e;
        c = f;
    }
}

int main() {
    func(1, 3);
    return 0;
}