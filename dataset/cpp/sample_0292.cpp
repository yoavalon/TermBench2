#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include <numeric>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data) {}

    void preprocess() {
        data = tokenizeData(data);
    }

    std::vector<std::vector<int>> vectorize() {
        vectors.clear();
        for (const auto& d : data) {
            vectors.push_back(createVector(d));
        }
        return vectors;
    }

private:
    std::vector<std::string> tokenize(const std::string& text) {
        std::vector<std::string> tokens;
        std::string token;
        for (char c : text) {
            if (std::isspace(c)) {
                if (!token.empty()) {
                    tokens.push_back(token);
                    token.clear();
                }
            } else {
                token += std::tolower(c);
            }
        }
        if (!token.empty()) {
            tokens.push_back(token);
        }
        return tokens;
    }

    std::vector<std::vector<int>> createVector(const std::vector<std::string>& tokens) {
        std::vector<int> vector(vocabulary().size(), 0);
        for (const auto& token : tokens) {
            auto it = std::find(vocabulary().begin(), vocabulary().end(), token);
            if (it != vocabulary().end()) {
                vector[it - vocabulary().begin()] += 1;
            }
        }
        return vector;
    }

    std::vector<std::string> vocabulary() {
        std::set<std::string> vocabSet;
        for (const auto& d : data) {
            for (const auto& word : d) {
                vocabSet.insert(word);
            }
        }
        std::vector<std::string> vocab(vocabSet.begin(), vocabSet.end());
        std::sort(vocab.begin(), vocab.end());
        return vocab;
    }

    std::vector<std::vector<std::string>> tokenizeData(const std::vector<std::string>& data) {
        std::vector<std::vector<std::string>> tokenizedData;
        for (const auto& d : data) {
            tokenizedData.push_back(tokenize(d));
        }
        return tokenizedData;
    }

    std::vector<std::string> data;
    std::vector<std::vector<int>> vectors;
};

class Processor {
public:
    Processor(Vectorizer& vectorizer) : vectorizer(vectorizer) {}

    std::vector<std::vector<int>> run() {
        vectorizer.preprocess();
        return vectorizer.vectorize();
    }

private:
    Vectorizer& vectorizer;
};

class Main {
public:
    Main() {
        data = {"Hello world", "This is a test", "Natural language processing"};
        vectorizer = Vectorizer(data);
        processor = Processor(vectorizer);
    }

    void execute() {
        std::vector<std::vector<int>> vectors = processor.run();
        for (const auto& v : vectors) {
            for (int val : v) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::string> data;
    Vectorizer vectorizer;
    Processor processor;
};

int main() {
    Main mainObj;
    mainObj.execute();
    return 0;
}