#include <stdio.h>

int calc_altitude(int target, int current, int rate, int max_alt) {
    if (current >= target || current + rate > max_alt) {
        return current;
    }
    return calc_altitude(target, current + rate, rate, max_alt);
}

int main() {
    printf("%d\n", calc_altitude(30000, 0, 1000, 40000));
    return 0;
}