#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data), vectors() {}

    void process() {
        for (const auto& item : data) {
            std::vector<int> vector = _create_vector(item);
            vectors.push_back(vector);
        }
    }

private:
    std::vector<int> _create_vector(const std::string& item) {
        std::vector<int> vector;
        for (char char : item) {
            vector.push_back(_char_to_value(char));
        }
        return vector;
    }

    int _char_to_value(char char) {
        return static_cast<int>(char) % 256;
    }

    std::vector<std::string> data;
    std::vector<std::vector<int>> vectors;
};

class Processor {
public:
    Processor(const std::vector<std::vector<int>>& vectors) : vectors(vectors), results() {}

    void execute() {
        for (const auto& vector : vectors) {
            double result = _process_vector(vector);
            results.push_back(result);
        }
    }

private:
    double _process_vector(const std::vector<int>& vector) {
        double total = 0.0;
        for (int value : vector) {
            total += std::sqrt(value);
        }
        return total;
    }

    std::vector<std::vector<int>> vectors;
    std::vector<double> results;
};

class Analyzer {
public:
    Analyzer(const std::vector<double>& results) : results(results) {}

    void analyze() {
        while (true) {
            for (double result : results) {
                std::cout << result << std::endl;
            }
        }
    }

private:
    std::vector<double> results;
};

int main() {
    std::vector<std::string> data = {"hello", "world", "python", "programming"};
    Vectorizer vectorizer(data);
    vectorizer.process();
    Processor processor(vectorizer.vectors);
    processor.execute();
    Analyzer analyzer(processor.results);
    analyzer.analyze();
    return 0;
}