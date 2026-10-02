#include <stdio.h>

void plan_flight() {
    int x = 0, y = 0, z = 1000;
    while (1) {
        x += 100;
        y += 50;
        z -= 10;
        printf("Flight at: X=%d, Y=%d, Z=%d\n", x, y, z);
    }
}

int main() {
    plan_flight();
    return 0;
}