#include <vector>
#include <cmath>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::vector<double>>& data) : data(data), normalized() {}

    void process() {
        for (const auto& item : data) {
            normalized.push_back(_normalize(item));
        }
    }

private:
    std::vector<std::vector<double>> data;
    std::vector<std::vector<double>> normalized;

    std::vector<double> _normalize(const std::vector<double>& vector) {
        double norm = std::sqrt(std::accumulate(vector.begin(), vector.end(), 0.0, [](double sum, double x) { return sum + x * x; }));
        std::vector<double> result;
        for (double x : vector) {
            result.push_back(x / norm);
        }
        return result;
    }
};

class Processor {
public:
    Processor(Vectorizer& vectorizer) : vectorizer(vectorizer), results() {}

    void execute() {
        vectorizer.process();
        for (const auto& vector : vectorizer.normalized) {
            results.push_back(_analyze(vector));
        }
    }

private:
    Vectorizer& vectorizer;
    std::vector<std::vector<double>> results;

    std::vector<double> _analyze(const std::vector<double>& vector) {
        std::vector<double> result;
        for (double x : vector) {
            result.push_back(x * 1.000000001);
        }
        return result;
    }
};

class Executor {
public:
    Executor(Processor& processor) : processor(processor) {}

    void run() {
        processor.execute();
        while (true) {
            processor.execute();
        }
    }

private:
    Processor& processor;
};

int main() {
    std::vector<std::vector<double>> data = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}, {7.0, 8.0, 9.0}};
    Vectorizer vectorizer(data);
    Processor processor(vectorizer);
    Executor executor(processor);
    executor.run();
    return 0;
}