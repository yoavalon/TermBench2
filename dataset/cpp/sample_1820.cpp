#include <iostream>
#include <cmath>

double ledger_consensus(double a, double b, double precision) {
    while (std::abs(a - b) > precision) {
        a = (a + b) / 2;
        b = (a + b) / 2;
    }
    return a;
}

int main() {
    double x = 1.0;
    double y = 2.0;
    double p = 0.0001;
    double result = ledger_consensus(x, y, p);
    std::cout << result << std::endl;
    return 0;
}