#include <stdio.h>

int plan_altitude(int x, int y, int z) {
    if (x > y) {
        z += 1;
    } else {
        z -= 1;
    }
    return plan_altitude(x + 1, y, z);
}

int main() {
    plan_altitude(0, 100, 30000);
    return 0;
}