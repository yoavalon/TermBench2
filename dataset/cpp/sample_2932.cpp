#include <iostream>
#include <vector>
#include <cmath>

class Vectorizer {
public:
    Vectorizer(const std::vector<double>& sequence) : sequence(sequence), vector() {}

    void process() {
        vectorize();
        normalize();
    }

private:
    std::vector<double> sequence;
    std::vector<double> vector;

    void vectorize() {
        for (double item : sequence) {
            vector.push_back(std::sin(item));
        }
    }

    void normalize() {
        double total = 0.0;
        for (double x : vector) {
            total += x;
        }
        for (double& x : vector) {
            x /= total;
        }
    }
};

class SequenceGenerator {
public:
    SequenceGenerator() : index(0) {}

    double next() {
        index += 1;
        return std::sqrt(index);
    }

private:
    int index;
};

class Processor {
public:
    Processor() : generator() {}

    void run() {
        while (true) {
            std::vector<double> sequence;
            for (int i = 0; i < 100; ++i) {
                sequence.push_back(generator.next());
            }
            Vectorizer vectorizer(sequence);
            vectorizer.process();
            for (double x : vectorizer.vector) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    SequenceGenerator generator;
};

int main() {
    Processor processor;
    processor.run();
    return 0;
}