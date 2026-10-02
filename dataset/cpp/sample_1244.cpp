#include <iostream>
#include <vector>

std::vector<int> plan_flight_trajectory() {
    std::vector<int> a = {1000, 2000, 3000, 4000, 5000};
    std::vector<int> b = {2000, 3000, 4000, 5000, 6000};
    std::vector<int> c = {3000, 4000, 5000, 6000, 7000};
    std::vector<int> d = {4000, 5000, 6000, 7000, 8000};
    std::vector<int> e = {5000, 6000, 7000, 8000, 9000};
    for (int i = 0; i < 5; i++) {
        if (a[i] > b[i] || c[i] < d[i]) {
            e[i] = e[i] + 1000;
        } else {
            e[i] = e[i] - 500;
        }
    }
    return e;
}

int main() {
    plan_flight_trajectory();
    return 0;
}