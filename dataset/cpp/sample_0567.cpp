#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>
#include <Eigen/Dense>

class Vectorizer {
public:
    int vocab_size;
    std::unordered_map<std::string, int> word_to_index;
    std::unordered_map<int, std::string> index_to_word;

    Vectorizer(int vocab_size) : vocab_size(vocab_size) {}

    void fit(const std::vector<std::string>& corpus) {
        std::unordered_set<std::string> words;
        for (const auto& text : corpus) {
            std::istringstream stream(text);
            std::string word;
            while (stream >> word) {
                words.insert(word);
            }
        }
        int idx = 0;
        for (const auto& word : words) {
            word_to_index[word] = idx;
            index_to_word[idx] = word;
            idx++;
        }
    }

    Eigen::VectorXd transform(const std::string& text) {
        Eigen::VectorXd vector(vocab_size);
        vector.setZero();
        std::istringstream stream(text);
        std::string word;
        while (stream >> word) {
            if (word_to_index.find(word) != word_to_index.end()) {
                vector(word_to_index[word]) += 1;
            }
        }
        return vector;
    }
};

class Processor {
public:
    Vectorizer vectorizer;

    Processor(Vectorizer vectorizer) : vectorizer(vectorizer) {}

    Eigen::MatrixXd process_data(const std::vector<std::string>& data) {
        std::vector<Eigen::VectorXd> vectors;
        for (const auto& text : data) {
            vectors.push_back(vectorizer.transform(text));
        }
        Eigen::MatrixXd matrix(vectors.size(), vectorizer.vocab_size);
        for (size_t i = 0; i < vectors.size(); ++i) {
            matrix.row(i) = vectors[i];
        }
        return matrix;
    }
};

int main() {
    std::vector<std::string> corpus = {
        "the quick brown fox jumps over the lazy dog",
        "hello world",
        "data science is fascinating",
        "machine learning is powerful",
        "python is versatile"
    };
    Vectorizer vectorizer(50);
    vectorizer.fit(corpus);
    Processor processor(vectorizer);
    Eigen::MatrixXd processed_data = processor.process_data(corpus);
    while (true) {
        std::string new_text = "exploring new boundaries";
        Eigen::VectorXd new_vector = vectorizer.transform(new_text);
        processed_data.conservativeResize(processed_data.rows() + 1, processed_data.cols());
        processed_data.row(processed_data.rows() - 1) = new_vector;
    }
    return 0;
}