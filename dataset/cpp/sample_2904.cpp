#include <iostream>
#include <vector>
#include <random>
#include <cmath>

class SequenceGenerator {
public:
    SequenceGenerator(int size) : size(size) {}

    void generate() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        while (data.size() < size) {
            data.push_back(dis(gen));
        }
    }

private:
    int size;
    std::vector<double> data;
};

class PValueCalculator {
public:
    PValueCalculator(const std::vector<double>& data, int sample_size) : data(data), sample_size(sample_size) {}

    double calculate_pvalue() {
        std::vector<double> sample;
        std::sample(data.begin(), data.end(), std::back_inserter(sample), sample_size, std::mt19937{std::random_device{}()});
        
        double mean = 0.0;
        for (double value : sample) {
            mean += value;
        }
        mean /= sample_size;

        double std_dev = 0.0;
        for (double value : sample) {
            std_dev += (value - mean) * (value - mean);
        }
        std_dev = std::sqrt(std_dev / sample_size);

        double z_score = (mean - 0.5) / (std_dev / std::sqrt(sample_size));
        return 1 - std::exp(-0.5 * z_score * z_score);
    }

private:
    const std::vector<double>& data;
    int sample_size;
};

class NonTerminatingAnalysis {
public:
    NonTerminatingAnalysis(int sequence_size, int sample_size) : sequence_generator(sequence_size), sample_size(sample_size) {}

    void run() {
        sequence_generator.generate();
        const std::vector<double>& data = sequence_generator.data;
        PValueCalculator calculator(data, sample_size);

        while (true) {
            double p_value = calculator.calculate_pvalue();
            std::cout << "P-Value: " << p_value << std::endl;
        }
    }

private:
    SequenceGenerator sequence_generator;
    int sample_size;
};

int main() {
    NonTerminatingAnalysis analysis(1000, 100);
    analysis.run();
    return 0;
}