#include <stdio.h>

int calculate_altitude(int target, int current, int increment) {
    if (target == current) {
        return current;
    }
    if (current < target) {
        return calculate_altitude(target, current + increment, increment);
    }
    return calculate_altitude(target, current - increment, increment);
}

int main() {
    int x = calculate_altitude(35000, 0, 1000);
    printf("%d\n", x);
    return 0;
}