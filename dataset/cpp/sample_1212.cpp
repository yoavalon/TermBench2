#include <iostream>

double data_mutations() {
    double x = 1.0;
    double decay = 0.9;
    double epsilon = 0.001;
    while (x > epsilon) {
        x *= decay;
    }
    return x;
}

int main() {
    data_mutations();
    return 0;
}