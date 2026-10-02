#include <stdio.h>

void plan_trajectory() {
    double a = 1000.0;
    double b = 0.0001;
    double c = 0.0002;
    for (int i = 0; i < 10000; i++) {
        a = a - b + c;
    }
    printf("%f\n", a);
}

int main() {
    plan_trajectory();
    return 0;
}