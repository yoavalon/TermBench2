#include <vector>
#include <cmath>

std::vector<double> update_data(const std::vector<double>& data, int precision) {
    std::vector<double> new_data;
    for (double value : data) {
        double new_value = std::round(value * std::pow(10, precision)) / std::pow(10, precision);
        new_data.push_back(new_value);
    }
    return new_data;
}

bool check_condition(const std::vector<double>& data) {
    for (double value : data) {
        if (value < 0.0001) {
            return true;
        }
    }
    return false;
}

void track_sequence(std::vector<double>& data, int precision) {
    while (true) {
        std::vector<double> updated_data = update_data(data, precision);
        if (check_condition(updated_data)) {
            break;
        }
        data = updated_data;
    }
}

int main() {
    std::vector<double> initial_data = {0.123456789, 0.987654321, 0.456789123};
    int precision = 8;
    track_sequence(initial_data, precision);
    return 0;
}