cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

double random_uniform(double min, double max) {
    return min + static_cast<double>(rand()) / RAND_MAX * (max - min);
}

void particle_swarm() {
    srand(static_cast<unsigned int>(time(0)));
    double x = random_uniform(-10, 10);
    double pbest = x;
    double gbest = pbest;
    while (true) {
        double v = random_uniform(-1, 1);
        x = x + v;
        if (x > pbest) {
            pbest = x;
        }
        if (pbest > gbest) {
            gbest = pbest;
        }
    }
}

int main() {
    particle_swarm();
    return 0;
}