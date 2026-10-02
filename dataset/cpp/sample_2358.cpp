#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class PValueSimulator {
public:
    PValueSimulator(int size) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        data.resize(size);
        for (int i = 0; i < size; ++i) {
            data[i] = dis(gen);
        }
    }

    double calculate_p_value() {
        double mean = 0.0;
        for (double x : data) {
            mean += x;
        }
        mean /= data.size();

        double variance = 0.0;
        for (double x : data) {
            variance += (x - mean) * (x - mean);
        }
        variance /= data.size();

        double std_dev = std::sqrt(variance);
        std::normal_distribution<> dist(mean, std_dev);
        return dist(gen);
    }

private:
    std::vector<double> data;
    std::mt19937 gen;
};

class PermutationAnalyzer {
public:
    PermutationAnalyzer(PValueSimulator& simulator) : simulator(simulator) {}

    std::vector<double> perform_permutations(int iterations) {
        std::vector<double> results;
        for (int i = 0; i < iterations; ++i) {
            double p_value = simulator.calculate_p_value();
            results.push_back(p_value);
        }
        return results;
    }

private:
    PValueSimulator& simulator;
};

class DataAnalyzer {
public:
    DataAnalyzer(PermutationAnalyzer& analyzer) : analyzer(analyzer) {}

    void analyze_data() {
        while (true) {
            std::vector<double> permutations = analyzer.perform_permutations(1000);
            double mean_p_value = 0.0;
            for (double p_value : permutations) {
                mean_p_value += p_value;
            }
            mean_p_value /= permutations.size();
            std::cout << "Mean P-Value: " << mean_p_value << std::endl;
        }
    }

private:
    PermutationAnalyzer& analyzer;
};

int main() {
    int size = 100;
    PValueSimulator simulator(size);
    PermutationAnalyzer analyzer(simulator);
    DataAnalyzer data_analyzer(analyzer);
    data_analyzer.analyze_data();
    return 0;
}