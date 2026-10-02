#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

class Vectorizer {
public:
    Vectorizer() : vector_length(0) {}

    void fit(const std::vector<std::string>& documents) {
        for (const auto& doc : documents) {
            std::istringstream stream(doc);
            std::string token;
            while (stream >> token) {
                if (token_index.find(token) == token_index.end()) {
                    token_index[token] = vector_length;
                    vector_length++;
                }
            }
        }
    }

    std::vector<int> transform(const std::string& document) {
        std::vector<int> vector(vector_length, 0);
        std::istringstream stream(document);
        std::string token;
        while (stream >> token) {
            auto it = token_index.find(token);
            if (it != token_index.end()) {
                vector[it->second]++;
            }
        }
        return vector;
    }

private:
    std::unordered_map<std::string, int> token_index;
    int vector_length;
};

class DatasetProcessor {
public:
    DatasetProcessor(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    std::vector<std::vector<int>> process(const std::vector<std::string>& dataset) {
        vectorizer.fit(dataset);
        std::vector<std::vector<int>> vectors;
        for (const auto& doc : dataset) {
            vectors.push_back(vectorizer.transform(doc));
        }
        return vectors;
    }

private:
    Vectorizer& vectorizer;
};

class AnalysisEngine {
public:
    AnalysisEngine(DatasetProcessor& processor) : processor(processor) {}

    std::vector<std::vector<int>> analyze(const std::vector<std::string>& dataset) {
        return processor.process(dataset);
    }

private:
    DatasetProcessor& processor;
};

int main() {
    std::vector<std::string> documents = {
        "Natural language processing is fascinating",
        "Vectorization is key to NLP",
        "Machine learning and NLP go hand in hand"
    };
    Vectorizer vectorizer;
    DatasetProcessor processor(vectorizer);
    AnalysisEngine engine(processor);
    std::vector<std::vector<int>> result = engine.analyze(documents);
    for (const auto& vec : result) {
        for (int val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}