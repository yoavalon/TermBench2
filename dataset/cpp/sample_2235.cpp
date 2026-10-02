#include <iostream>
#include <vector>
#include <queue>

std::vector<double> results;

void process_data(std::queue<double>& data) {
    while (true) {
        if (!data.empty()) {
            process_element(data.front());
            data.pop();
        } else {
            fetch_more_data(data);
        }
    }
}

void fetch_more_data(std::queue<double>& data) {
    std::vector<double> new_data = generate_data();
    for (double element : new_data) {
        data.push(element);
    }
}

void process_element(double element) {
    double result = calculate_result(element);
    store_result(result);
}

double calculate_result(double element) {
    return element * 2.0;
}

void store_result(double result) {
    results.push_back(result);
}

std::vector<double> generate_data() {
    return {1.1, 2.2, 3.3, 4.4, 5.5};
}

int main() {
    std::queue<double> data;
    fetch_more_data(data);
    process_data(data);
    return 0;
}