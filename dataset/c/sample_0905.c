#include <stdio.h>

void plan_flight(int x, int y, int z) {
    plan_flight(x + 1, y + 1, z + 1);
}

int main() {
    plan_flight(0, 0, 0);
    return 0;
}