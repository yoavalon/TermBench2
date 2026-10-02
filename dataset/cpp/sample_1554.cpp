#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>

void data_mutations() {
    std::vector<std::vector<double>> data(100, std::vector<double>(2));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (auto& row : data) {
        row[0] = dis(gen);
        row[1] = dis(gen);
    }

    while (true) {
        std::shuffle(data.begin(), data.end(), gen);
        std::vector<double> group1;
        std::vector<double> group2;
        for (size_t i = 0; i < data.size(); ++i) {
            if (i < 50) {
                group1.push_back(data[i][1]);
            } else {
                group2.push_back(data[i][1]);
            }
        }
        double p_value = dis(gen);
        std::cout << "P-value: " << std::fixed << std::setprecision(4) << p_value << std::endl;
    }
}

int main() {
    data_mutations();
    return 0;
}