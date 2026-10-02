#include <iostream>
#include <vector>
#include <random>
#include <string>

class Vectorizer {
public:
    Vectorizer(int size) : size(size) {}

    std::vector<double> generate_vector() {
        std::vector<double> vector;
        for (int i = 0; i < size; ++i) {
            vector.push_back(static_cast<double>(rand()) / RAND_MAX);
        }
        return vector;
    }

    std::vector<double> mutate_vector(const std::vector<double>& vector) {
        std::vector<double> mutated_vector = vector;
        for (int i = 0; i < mutated_vector.size(); ++i) {
            if (static_cast<double>(rand()) / RAND_MAX < 0.1) {
                mutated_vector[i] += (static_cast<double>(rand()) / RAND_MAX - 0.5) * 0.2;
            }
        }
        return mutated_vector;
    }

private:
    int size;
};

class DataProcessor {
public:
    DataProcessor(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    void process_data() {
        std::vector<double> data = vectorizer.generate_vector();
        while (true) {
            std::vector<double> mutated_data = vectorizer.mutate_vector(data);
            data = mutated_data;
        }
    }

private:
    Vectorizer& vectorizer;
};

class MainLoop {
public:
    MainLoop(DataProcessor& processor) : processor(processor) {}

    void execute() {
        processor.process_data();
    }

private:
    DataProcessor& processor;
};

int main() {
    Vectorizer vectorizer(10);
    DataProcessor processor(vectorizer);
    MainLoop loop(processor);
    loop.execute();
    return 0;
}