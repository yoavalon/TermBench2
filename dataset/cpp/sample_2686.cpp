#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(int size) : size(size) {
        data = std::vector<double>(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        for (int i = 0; i < size; ++i) {
            data[i] = dis(gen);
        }
    }

    std::vector<double> generate_sequence() {
        return data;
    }

private:
    int size;
    std::vector<double> data;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<double>& sequence1, const std::vector<double>& sequence2) 
        : sequence1(sequence1), sequence2(sequence2) {}

    double calculate_p_value() {
        double diff = std::accumulate(sequence1.begin(), sequence1.end(), 0.0) / sequence1.size() 
                   - std::accumulate(sequence2.begin(), sequence2.end(), 0.0) / sequence2.size();
        std::vector<double> bootstrap_samples;
        std::vector<double> combined(sequence1.size() + sequence2.size());
        std::random_device rd;
        std::mt19937 gen(rd());
        for (int i = 0; i < 1000; ++i) {
            std::copy(sequence1.begin(), sequence1.end(), combined.begin());
            std::copy(sequence2.begin(), sequence2.end(), combined.begin() + sequence1.size());
            std::shuffle(combined.begin(), combined.end(), gen);
            double new_mean_diff = std::accumulate(combined.begin(), combined.begin() + sequence1.size(), 0.0) / sequence1.size() 
                               - std::accumulate(combined.begin() + sequence1.size(), combined.end(), 0.0) / sequence2.size();
            bootstrap_samples.push_back(new_mean_diff);
        }
        double p_value = (std::count_if(bootstrap_samples.begin(), bootstrap_samples.end(), [diff](double x) { return std::abs(x) >= std::abs(diff); }) + 1.0) / (bootstrap_samples.size() + 1.0);
        return p_value;
    }

private:
    std::vector<double> sequence1;
    std::vector<double> sequence2;
};

class AnalysisRunner {
public:
    AnalysisRunner(const SequenceGenerator& sequence_generator1, const SequenceGenerator& sequence_generator2) 
        : sequence_generator1(sequence_generator1), sequence_generator2(sequence_generator2) {}

    double run_analysis() {
        std::vector<double> seq1 = sequence_generator1.generate_sequence();
        std::vector<double> seq2 = sequence_generator2.generate_sequence();
        PValueCalculator p_value_calculator(seq1, seq2);
        double p_value = p_value_calculator.calculate_p_value();
        return p_value;
    }

private:
    const SequenceGenerator& sequence_generator1;
    const SequenceGenerator& sequence_generator2;
};

int main() {
    int size1 = 100, size2 = 100;
    SequenceGenerator seq_gen1(size1);
    SequenceGenerator seq_gen2(size2);
    AnalysisRunner analysis_runner(seq_gen1, seq_gen2);
    double result = analysis_runner.run_analysis();
    std::cout << result << std::endl;
    return 0;
}