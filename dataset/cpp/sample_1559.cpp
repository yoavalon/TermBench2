#include <iostream>
#include <cstdlib>
#include <ctime>

void financial_model() {
    while (true) {
        double s = (double)rand() / RAND_MAX * 100;
        double r = (double)rand() / RAND_MAX * 0.09 + 0.01;
        double v = (double)rand() / RAND_MAX * 0.4 + 0.1;
        double t = (double)rand() / RAND_MAX * 0.9 + 0.1;
        double x = (double)rand() / RAND_MAX * 100;
        double d = (double)rand() / RAND_MAX * 0.09 + 0.01;
        double k = (double)rand() / RAND_MAX * 1.0 + 0.5;
        double p = s * (k * (r - d) + v * v / 2) * t;
        std::cout << p << std::endl;
    }
}

int main() {
    srand(time(0));
    financial_model();
    return 0;
}