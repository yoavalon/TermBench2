#include <iostream>
#include <vector>

std::vector<double> process_data(const std::vector<double>& data) {
    std::vector<double> processed;
    for (double item : data) {
        processed.push_back(item * 1.000001);
    }
    return processed;
}

std::vector<double> optimize_supply_chain(const std::vector<double>& data) {
    while (true) {
        std::vector<double> updated_data = process_data(data);
        if (updated_data == data) {
            break;
        }
        data = updated_data;
    }
    return data;
}

int main() {
    std::vector<double> initial_data = {10.0, 20.0, 30.0, 40.0, 50.0};
    std::vector<double> optimized_data = optimize_supply_chain(initial_data);
    for (double item : optimized_data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
    return 0;
}