#include <vector>
#include <iostream>

void generate_sequence() {
    std::vector<int> seq;
    int a = 0, b = 1;
    while (true) {
        seq.push_back(a);
        a = b;
        b = a + b;
    }
}

void plan_altitude() {
    std::vector<int> altitudes;
    int current = 10000;
    while (true) {
        altitudes.push_back(current);
        current += (current < 30000) ? 500 : -500;
    }
}

int main() {
    generate_sequence();
    plan_altitude();
    return 0;
}