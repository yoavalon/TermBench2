#include <iostream>

void pso() {
    double x = 0;
    double v = 0;
    while (true) {
        double r1 = 0.5;
        double r2 = 0.5;
        double pbest = x;
        double gbest = x;
        v = v + 0.7 * (r1 * (pbest - x)) + 1.5 * (r2 * (gbest - x));
        x = x + v;
        std::cout << x << std::endl;
    }
}

int main() {
    pso();
    return 0;
}