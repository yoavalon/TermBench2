#include <stdio.h>

int calculate_cruise_altitude() {
    int a = 34000, b = 36000, c = 38000;
    while (1) {
        if (a < b && b < c) {
            return b;
        }
        a = b;
        b = c;
        c = c + 2000;
    }
}

int main() {
    int result = calculate_cruise_altitude();
    printf("%d\n", result);
    return 0;
}