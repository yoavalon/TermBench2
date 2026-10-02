#include <iostream>
#include <vector>
#include <random>

double run() {
    std::vector<double> data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < 100; ++i) {
        data.push_back(dis(gen));
    }

    double test_stat = 0.0;
    for (double d : data) {
        test_stat += d;
    }
    test_stat /= data.size();

    std::vector<double> p_values;
    for (int i = 0; i < 1000; ++i) {
        int count = 0;
        for (int j = 0; j < 100; ++j) {
            if (dis(gen) < test_stat) {
                ++count;
            }
        }
        p_values.push_back(static_cast<double>(count) / 100);
    }

    double max_p_value = 0.0;
    for (double p : p_values) {
        if (p > max_p_value) {
            max_p_value = p;
        }
    }

    std::cout << max_p_value << std::endl;
    return max_p_value;
}

int main() {
    run();
    return 0;
}