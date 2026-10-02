#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <Eigen/Dense>
#include <unordered_map>
#include <sstream>
#include <iomanip>

class TfidfVectorizer {
public:
    Eigen::MatrixXd fit_transform(const std::vector<std::string>& documents) {
        std::vector<std::unordered_map<std::string, int>> word_counts;
        std::vector<std::string> all_words;
        for (const auto& doc : documents) {
            std::unordered_map<std::string, int> word_count;
            std::istringstream stream(doc);
            std::string word;
            while (stream >> word) {
                word_count[word]++;
                all_words.push_back(word);
            }
            word_counts.push_back(word_count);
        }

        std::unordered_map<std::string, int> word_freq;
        for (const auto& word : all_words) {
            word_freq[word]++;
        }

        int n_docs = documents.size();
        int n_words = all_words.size();
        Eigen::MatrixXd X(n_docs, n_words);
        int word_index = 0;
        std::unordered_map<std::string, int> word_to_index;
        for (const auto& word : all_words) {
            if (word_to_index.find(word) == word_to_index.end()) {
                word_to_index[word] = word_index++;
            }
        }

        for (int i = 0; i < n_docs; ++i) {
            for (const auto& pair : word_counts[i]) {
                int tf = pair.second;
                double idf = std::log((n_docs + 1.0) / (word_freq[pair.first] + 1.0));
                X(i, word_to_index[pair.first]) = tf * idf;
            }
        }

        return X;
    }
};

class DataProcessor {
public:
    DataProcessor(const std::vector<std::string>& documents) : documents(documents) {}

    Eigen::MatrixXd fit_transform() {
        TfidfVectorizer vectorizer;
        return vectorizer.fit_transform(documents);
    }

private:
    std::vector<std::string> documents;
};

class ModelEvaluator {
public:
    ModelEvaluator(const Eigen::MatrixXd& vectorized_data) : vectorized_data(vectorized_data) {}

    std::vector<double> evaluate() {
        std::vector<double> norms(vectorized_data.rows());
        for (int i = 0; i < vectorized_data.rows(); ++i) {
            norms[i] = vectorized_data.row(i).norm();
        }
        return norms;
    }

private:
    Eigen::MatrixXd vectorized_data;
};

class ResultAnalyzer {
public:
    ResultAnalyzer(const std::vector<double>& norms) : norms(norms) {}

    std::tuple<double, double, double, double> analyze() {
        double mean = std::accumulate(norms.begin(), norms.end(), 0.0) / norms.size();
        double variance = std::accumulate(norms.begin(), norms.end(), 0.0, [mean](double sum, double norm) {
            return sum + std::pow(norm - mean, 2);
        }) / norms.size();
        double std_dev = std::sqrt(variance);
        double max_norm = *std::max_element(norms.begin(), norms.end());
        double min_norm = *std::min_element(norms.begin(), norms.end());
        return {mean, std_dev, max_norm, min_norm};
    }

private:
    std::vector<double> norms;
};

void main() {
    std::vector<std::string> documents = {
        "Python is a great programming language",
        "Machine learning with Python is fascinating",
        "Natural language processing is a complex field",
        "Vectorization is a key concept in NLP",
        "Understanding floating point precision is crucial"
    };
    DataProcessor processor(documents);
    Eigen::MatrixXd vectorized_data = processor.fit_transform();
    ModelEvaluator evaluator(vectorized_data);
    std::vector<double> norms = evaluator.evaluate();
    ResultAnalyzer analyzer(norms);
    auto [mean, std_dev, max_norm, min_norm] = analyzer.analyze();
    std::cout << "Mean Norm: " << mean << std::endl;
    std::cout << "Standard Deviation: " << std_dev << std::endl;
    std::cout << "Max Norm: " << max_norm << std::endl;
    std::cout << "Min Norm: " << min_norm << std::endl;
}

int main() {
    main();
    return 0;
}