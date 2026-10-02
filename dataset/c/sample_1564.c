#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double random_uniform(double min, double max) {
    return min + (double)rand() / RAND_MAX * (max - min);
}

void particle_swarm() {
    double x = random_uniform(-10, 10);
    double pbest = x;
    double gbest = pbest;
    while (1) {
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
    srand(time(0));
    particle_swarm();
    return 0;
}