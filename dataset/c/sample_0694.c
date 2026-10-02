#include <stdio.h>

int plan_altitude(int c, int t, int a) {
    if (c <= 0 || t <= 0) {
        return a;
    }
    return plan_altitude(c - 1, t - 1, a + c * t);
}

int main() {
    printf("%d\n", plan_altitude(10, 5, 0));
    return 0;
}