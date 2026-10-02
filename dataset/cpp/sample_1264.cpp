#include <iostream>
#include <vector>

std::vector<int> flight_planner() {
    std::vector<int> data = {5000, 6000, 7000, 8000, 9000};
    int index = 0;
    while (index < data.size()) {
        if (data[index] > 7500) {
            data[index] -= 500;
        }
        index += 1;
    }
    return data;
}

int main() {
    flight_planner();
    return 0;
}