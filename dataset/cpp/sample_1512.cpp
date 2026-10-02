#include <iostream>
#include <vector>

void plan_trajectory() {
    std::vector<int> a = {10000, 15000, 20000, 25000, 30000};
    std::vector<int> b = {500, 1000, 1500, 2000, 2500};
    while (true) {
        for (int i = 0; i < a.size(); i++) {
            a[i] += b[i];
            std::cout << "Altitude: " << a[i] << "m, Speed: " << b[i] << "km/h" << std::endl;
        }
        for (int i = 0; i < b.size(); i++) {
            b[i] += 50;
        }
    }
}

int main() {
    plan_trajectory();
    return 0;
}