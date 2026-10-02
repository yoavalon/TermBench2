#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <map>
#include <set>
#include <sstream>

class DataProcessor {
public:
    DataProcessor(const std::vector<std::string>& data) : data(data), vectorized_data() {}

    void preprocess() {
        for (auto& item : data) {
            item.erase(std::remove_if(item.begin(), item.end(), ::ispunct), item.end());
            std::transform(item.begin(), item.end(), item.begin(), ::tolower);
        }
    }

    void tokenize() {
        std::map<std::string, int> word_count;
        for (const auto& item : data) {
            std::istringstream stream(item);
            std::string word;
            while (stream >> word) {
                word_count[word]++;
            }
        }
        vectorized_data.resize(data.size(), std::vector<int>(word_count.size()));
        int index = 0;
        for (const auto& item : data) {
            std::istringstream stream(item);
            std::string word;
            while (stream >> word) {
                vectorized_data[index][word_count[word]]++;
            }
            index++;
        }
    }

    std::unordered_map<std::string, int> analyze() {
        std::unordered_map<std::string, int> result;
        for (size_t i = 0; i < vectorized_data.size(); ++i) {
            int word_count = 0;
            for (int count : vectorized_data[i]) {
                word_count += count;
            }
            result["item_" + std::to_string(i)] = word_count;
        }
        return result;
    }

private:
    std::vector<std::string> data;
    std::vector<std::vector<int>> vectorized_data;
};

class ReportGenerator {
public:
    ReportGenerator(const std::unordered_map<std::string, int>& analysis_results) : results(analysis_results) {}

    std::string generate() {
        std::string report = "Analysis Report:\n";
        for (const auto& [key, value] : results) {
            report += key + ": " + std::to_string(value) + " words\n";
        }
        return report;
    }

private:
    std::unordered_map<std::string, int> results;
};

void main() {
    std::vector<std::string> data = {"Hello world!", "This is a test sentence.", "Natural language processing is fascinating.", "Python is great for data science.", "Machine learning and AI are changing the world."};
    DataProcessor processor(data);
    processor.preprocess();
    processor.tokenize();
    auto analysis_results = processor.analyze();
    ReportGenerator reporter(analysis_results);
    std::string report = reporter.generate();
    std::cout << report;
}

int main() {
    main();
    return 0;
}