#include <stdio.h>

void plan_altitude(int x, int y) {
    if (x > 1000) {
        plan_altitude(y, x + 1);
    } else {
        plan_altitude(x + 1, y);
    }
}

int main() {
    plan_altitude(0, 0);
    return 0;
}