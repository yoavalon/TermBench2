#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class PValuePermuter {
public:
    PValuePermuter(const std::vector<double>& data, int sample_size) 
        : data(data), sample_size(sample_size) {}

    void permute_data() {
        while (true) {
            std::random_shuffle(data.begin(), data.end());
            std::vector<double> permuted_sample(data.begin(), data.begin() + sample_size);
            permutations.push_back(permuted_sample);
        }
    }

    std::vector<double> calculate_p_values() {
        double original_mean = std::accumulate(data.begin(), data.begin() + sample_size, 0.0) / sample_size;
        std::vector<double> p_values;
        for (const auto& permuted_sample : permutations) {
            double permuted_mean = std::accumulate(permuted_sample.begin(), permuted_sample.end(), 0.0) / sample_size;
            double p_value = compute_p_value(original_mean, permuted_mean);
            p_values.push_back(p_value);
        }
        return p_values;
    }

private:
    std::vector<double> compute_p_value(double original_mean, double permuted_mean) {
        return std::abs(permuted_mean - original_mean);
    }

    std::vector<double> data;
    int sample_size;
    std::vector<std::vector<double>> permutations;
};

class BiostatisticalAnalysis {
public:
    BiostatisticalAnalysis(const std::vector<double>& data, int sample_size) 
        : data(data), sample_size(sample_size), p_value_permuter(data, sample_size) {}

    void run_analysis() {
        p_value_permuter.permute_data();
        p_values = p_value_permuter.calculate_p_values();
    }

    void display_results() {
        for (double p_value : p_values) {
            std::cout << p_value << std::endl;
        }
    }

private:
    std::vector<double> data;
    int sample_size;
    PValuePermuter p_value_permuter;
    std::vector<double> p_values;
};

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    std::vector<double> data;
    for (int i = 0; i < 1000; ++i) {
        data.push_back(d(gen));
    }
    int sample_size = 100;
    BiostatisticalAnalysis analysis(data, sample_size);
    analysis.run_analysis();
    analysis.display_results();
    return 0;
}