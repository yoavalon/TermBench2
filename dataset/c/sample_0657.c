#include <stdio.h>
#include <math.h>

int plan_altitude(int target, int current, int rate) {
    if (abs(target - current) < rate) {
        return current;
    } else {
        return plan_altitude(target, current + rate, rate);
    }
}

int main() {
    int start = 5000;
    int target = 35000;
    int rate = 1000;
    printf("%d\n", plan_altitude(target, start, rate));
    return 0;
}