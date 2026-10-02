#include <stdio.h>
#include <stdlib.h>

int plan_altitude(int target, int current, int step) {
    if (abs(target - current) <= step) {
        return current;
    }
    if (target > current) {
        return plan_altitude(target, current + step, step);
    } else {
        return plan_altitude(target, current - step, step);
    }
}

int main() {
    printf("%d\n", plan_altitude(35000, 10000, 5000));
    return 0;
}