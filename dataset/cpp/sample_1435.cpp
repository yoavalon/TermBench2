#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>
#include <sstream>

class Vectorizer {
public:
    Vectorizer(const std::vector<std::string>& data) : data(data), vectors(data.size(), std::vector<double>(100, 0.0)) {}

    void preprocess() {
        for (auto& d : data) {
            std::transform(d.begin(), d.end(), d.begin(), ::tolower);
            std::istringstream iss(d);
            std::string word;
            std::vector<std::string> processed_text;
            while (iss >> word) {
                processed_text.push_back(word);
            }
            data_processed.push_back(processed_text);
        }
    }

    void transform() {
        for (size_t i = 0; i < data_processed.size(); ++i) {
            for (const auto& word : data_processed[i]) {
                if (vocabulary.find(word) != vocabulary.end()) {
                    for (size_t j = 0; j < 100; ++j) {
                        vectors[i][j] += vocabulary[word][j];
                    }
                }
            }
        }
    }

    std::vector<std::vector<double>> fit_transform() {
        preprocess();
        build_vocabulary();
        transform();
        return vectors;
    }

private:
    void build_vocabulary() {
        vocabulary.clear();
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        for (const auto& text : data_processed) {
            for (const auto& word : text) {
                if (vocabulary.find(word) == vocabulary.end()) {
                    std::vector<double> vector(100);
                    for (auto& val : vector) {
                        val = dis(gen);
                    }
                    vocabulary[word] = vector;
                }
            }
        }
    }

    std::vector<std::string> data;
    std::vector<std::vector<std::string>> data_processed;
    std::unordered_map<std::string, std::vector<double>> vocabulary;
    std::vector<std::vector<double>> vectors;
};

std::vector<std::string> load_data() {
    return {"Example sentence one", "Another example sentence two", "Yet another example"};
}

int main() {
    auto data = load_data();
    Vectorizer vectorizer(data);
    auto vectors = vectorizer.fit_transform();

    for (const auto& vec : vectors) {
        for (double val : vec) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}