#include <stdio.h>

void plan_flight(int x, int y) {
    if (x < 0 || y < 0) {
        return;
    }
    printf("Flight at altitude %d, trajectory %d\n", x, y);
    plan_flight(x + 1, y + 1);
}

int main() {
    plan_flight(0, 0);
    return 0;
}