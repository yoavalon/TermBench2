#include <iostream>
#include <vector>
#include <cmath>

class SequenceSimulator {
public:
    SequenceSimulator(double a, double b, int n) : a(a), b(b), n(n) {}

    void generate_sequence() {
        for (int i = 0; i < n; ++i) {
            double value = a + i * b;
            sequence.push_back(value);
        }
    }

    std::vector<double> calculate_thermodynamic_states() {
        std::vector<double> states;
        for (double value : sequence) {
            double state = std::exp(-value);
            states.push_back(state);
        }
        return states;
    }

private:
    double a;
    double b;
    int n;
    std::vector<double> sequence;
};

class DataAnalyzer {
public:
    DataAnalyzer(const std::vector<double>& data) : data(data) {}

    double average() {
        double sum = 0.0;
        for (double d : data) {
            sum += d;
        }
        return sum / data.size();
    }

    double max_value() {
        return *std::max_element(data.begin(), data.end());
    }

    double min_value() {
        return *std::min_element(data.begin(), data.end());
    }

private:
    std::vector<double> data;
};

int main() {
    double a = 0;
    double b = 0.1;
    int n = 100;
    SequenceSimulator simulator(a, b, n);
    simulator.generate_sequence();
    std::vector<double> states = simulator.calculate_thermodynamic_states();
    DataAnalyzer analyzer(states);
    std::cout << "Average State: " << analyzer.average() << std::endl;
    std::cout << "Max State: " << analyzer.max_value() << std::endl;
    std::cout << "Min State: " << analyzer.min_value() << std::endl;
    return 0;
}