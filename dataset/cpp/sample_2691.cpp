#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

class SequenceSimulator {
public:
    SequenceSimulator(int a, int b, int n) : a(a), b(b), n(n) {}

    std::vector<int> generate_sequence() {
        std::vector<int> sequence;
        int current = a;
        for (int i = 0; i < n; ++i) {
            sequence.push_back(current);
            current = b * current;
        }
        return sequence;
    }

    std::map<std::string, double> analyze_sequence(const std::vector<int>& sequence) {
        std::map<std::string, double> analysis;
        int sum = std::accumulate(sequence.begin(), sequence.end(), 0);
        int max = *std::max_element(sequence.begin(), sequence.end());
        int min = *std::min_element(sequence.begin(), sequence.end());
        double mean = static_cast<double>(sum) / sequence.size();
        analysis["sum"] = sum;
        analysis["max"] = max;
        analysis["min"] = min;
        analysis["mean"] = mean;
        return analysis;
    }

private:
    int a;
    int b;
    int n;
};

class ThermodynamicState {
public:
    ThermodynamicState(double temperature, double pressure) : temperature(temperature), pressure(pressure) {}

    void update_state(const std::map<std::string, double>& sequence_analysis) {
        temperature = sequence_analysis.at("max");
        pressure = sequence_analysis.at("min");
    }

private:
    double temperature;
    double pressure;
};

void main() {
    SequenceSimulator sim(2, 3, 10);
    std::vector<int> seq = sim.generate_sequence();
    std::map<std::string, double> analysis = sim.analyze_sequence(seq);
    ThermodynamicState state(300, 1);
    state.update_state(analysis);
    std::cout << "Final Temperature: " << state.temperature << ", Final Pressure: " << state.pressure << std::endl;
}

int main() {
    main();
    return 0;
}