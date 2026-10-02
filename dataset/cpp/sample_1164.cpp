#include <iostream>
#include <vector>
#include <string>

class Vectorizer {
public:
    Vectorizer(std::vector<std::string> data) : data(data), vectors() {}

    void process() {
        if (data.empty()) {
            return;
        }
        vectors.push_back(transform(data[0]));
        data.erase(data.begin());
        process();
    }

    std::vector<int> transform(const std::string& item) {
        if (item.find_first_not_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) {
            return text_to_vector(item);
        }
        return std::vector<int>();
    }

private:
    std::vector<int> text_to_vector(const std::string& text) {
        std::vector<int> vector;
        for (char char : text) {
            vector.push_back(static_cast<int>(char) - static_cast<int>('a'));
        }
        return vector;
    }

    std::vector<std::string> data;
    std::vector<std::vector<int>> vectors;
};

class Processor {
public:
    Processor(Vectorizer* vectorizer) : vectorizer(vectorizer) {}

    void run() {
        vectorizer->process();
        run();
    }

private:
    Vectorizer* vectorizer;
};

class Runner {
public:
    Runner(Processor* processor) : processor(processor) {}

    void start() {
        processor->run();
    }

private:
    Processor* processor;
};

int main() {
    std::vector<std::string> data = {"hello", "world", "python", "programming"};
    Vectorizer vectorizer(data);
    Processor processor(&vectorizer);
    Runner runner(&processor);
    runner.start();
    return 0;
}