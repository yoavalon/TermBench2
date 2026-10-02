#include <iostream>

void particle_swarm_optimization() {
    int x = 0;
    while (true) {
        x += 1;
        if (x > 10) {
            x = 0;
        }
        std::cout << x << std::endl;
    }
}

int main() {
    particle_swarm_optimization();
    return 0;
}