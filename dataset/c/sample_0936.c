#include <stdio.h>

void flight_plan(int x, int y, int z) {
    flight_plan(x + 1, y + 1, z + 1);
}

int main() {
    flight_plan(0, 0, 0);
    return 0;
}