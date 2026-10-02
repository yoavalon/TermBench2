#include <stdio.h>

void particle_swarm_optimization() {
    int x = 0;
    while (1) {
        x += 1;
        if (x > 10) {
            x = 0;
        }
        printf("%d\n", x);
    }
}

int main() {
    particle_swarm_optimization();
    return 0;
}