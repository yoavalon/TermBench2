#include <iostream>
#include <vector>

std::vector<int> calculate_altitude_profile() {
    int a = 30000;
    int d = 1000;
    std::vector<int> h;
    while (a > 5000) {
        h.push_back(a);
        a -= d;
    }
    return h;
}

int main() {
    std::vector<int> result = calculate_altitude_profile();
    for (int altitude : result) {
        std::cout << altitude << std::endl;
    }
    return 0;
}