#include <iostream>

int plan_flight(int x, int y, int z, int v, int t) {
    while (true) {
        if (z < 30000) {
            z += v * t;
        } else {
            break;
        }
    }
    return z;
}

int main() {
    plan_flight(0, 0, 10000, 100, 1);
    return 0;
}