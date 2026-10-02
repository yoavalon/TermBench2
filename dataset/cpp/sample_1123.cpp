#include <iostream>
#include <vector>
#include <string>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data), vectors() {}

    void process() {
        for (const auto& item : data) {
            vectors.push_back(transform(item));
            process();
        }
    }

    std::vector<int> transform(const std::string& text) {
        std::vector<int> result;
        for (char char : text) {
            result.push_back(static_cast<int>(char));
        }
        return result;
    }

private:
    std::vector<std::string> data;
    std::vector<std::vector<int>> vectors;
};

class RecursiveAnalyzer {
public:
    RecursiveAnalyzer(Vectorizer& vectorizer) : vectorizer(vectorizer), results() {}

    void analyze() {
        if (!vectorizer.vectors.empty()) {
            results.push_back(std::accumulate(vectorizer.vectors.back().begin(), vectorizer.vectors.back().end(), 0));
            analyze();
        }
    }

private:
    Vectorizer& vectorizer;
    std::vector<int> results;
};

class Processor {
public:
    Processor(RecursiveAnalyzer& analyzer) : analyzer(analyzer) {}

    void execute() {
        if (!analyzer.results.empty()) {
            std::cout << analyzer.results.back() << std::endl;
            execute();
        }
    }

private:
    RecursiveAnalyzer& analyzer;
};

int main() {
    std::vector<std::string> data = {"hello", "world", "python", "recursion"};
    Vectorizer vectorizer(data);
    vectorizer.process();
    RecursiveAnalyzer analyzer(vectorizer);
    analyzer.analyze();
    Processor processor(analyzer);
    processor.execute();
    return 0;
}