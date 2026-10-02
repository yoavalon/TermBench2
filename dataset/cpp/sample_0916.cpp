#include <iostream>

int plan_altitude(int x, int y) {
    if (x > 1000) {
        return plan_altitude(x - 100, y + 50);
    } else {
        return plan_altitude(x + 50, y - 10);
    }
}

int main() {
    plan_altitude(0, 30000);
    return 0;
}