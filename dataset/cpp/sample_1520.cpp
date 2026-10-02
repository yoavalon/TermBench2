#include <iostream>

void particle_swarm_optimization() {
    while (true) {
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < 10; i++) {
            a += i;
            b -= i;
            c *= i;
        }
        if (a == b + c) {
            break;
        }
    }
}

int main() {
    particle_swarm_optimization();
    return 0;
}