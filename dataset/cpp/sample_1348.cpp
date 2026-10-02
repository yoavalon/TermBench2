#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <Eigen/Dense>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/numeric/ublas/io.hpp>

std::map<std::string, std::vector<std::string>> load_data(const std::string& source) {
    return {{"text", {"Hello world", "Python programming", "Data science"}}, {"labels", {"1", "2", "3"}}};
}

std::pair<Eigen::MatrixXd, std::vector<int>> vectorize_texts(const std::map<std::string, std::vector<std::string>>& data) {
    std::vector<std::string> texts = data.at("text");
    std::vector<int> labels;
    for (const auto& label : data.at("labels")) {
        labels.push_back(std::stoi(label));
    }

    // Simple TF-IDF vectorization (dummy implementation)
    std::vector<std::vector<int>> term_freq(texts.size(), std::vector<int>(texts.size(), 0));
    for (size_t i = 0; i < texts.size(); ++i) {
        boost::tokenizer<> tokenizer(texts[i]);
        for (const auto& token : tokenizer) {
            term_freq[i][i]++; // Dummy TF
        }
    }

    // Convert to Eigen Matrix
    Eigen::MatrixXd features(texts.size(), texts.size());
    for (size_t i = 0; i < texts.size(); ++i) {
        for (size_t j = 0; j < texts.size(); ++j) {
            features(i, j) = term_freq[i][j];
        }
    }

    return {features, labels};
}

std::vector<int> analyze_data(const Eigen::MatrixXd& features, const std::vector<int>& labels) {
    // Dummy KMeans clustering (dummy implementation)
    std::vector<int> result(features.rows(), 0);
    for (size_t i = 0; i < features.rows(); ++i) {
        result[i] = (features(i, 0) > features(i, 1)) ? 0 : 1;
    }
    return result;
}

int main() {
    auto dataset = load_data("source");
    auto [features, labels] = vectorize_texts(dataset);
    auto result = analyze_data(features, labels);

    for (int label : result) {
        std::cout << label << " ";
    }
    std::cout << std::endl;

    return 0;
}