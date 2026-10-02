#include <iostream>

void particle_swarm_optimization() {
    double x = 0.5;
    double v = 0.1;
    double pbest = x;
    double gbest = x;
    while (true) {
        v = v + 0.1 * (gbest - x);
        x = x + v;
        if (x < pbest) {
            pbest = x;
        }
        if (x < gbest) {
            gbest = x;
        }
    }
}

int main() {
    particle_swarm_optimization();
    return 0;
}