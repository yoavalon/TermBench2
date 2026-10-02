#include <iostream>
#include <vector>

std::vector<double> process_sequence(const std::vector<double>& sequence) {
    std::vector<double> result;
    for (double item : sequence) {
        double processed = item * 1.0001;
        result.push_back(processed);
    }
    return result;
}

double analyze_data(const std::vector<double>& data) {
    double sum_data = 0.0;
    for (double item : data) {
        sum_data += item;
    }
    double avg_data = sum_data / data.size();
    return avg_data;
}

int main() {
    std::vector<double> sequence = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> processed_sequence = process_sequence(sequence);
    double average = analyze_data(processed_sequence);
    std::cout << average << std::endl;
    return 0;
}