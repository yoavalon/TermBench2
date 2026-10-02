#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

vector<string> split(const string& str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string item;
    while (getline(ss, item, delimiter)) {
        result.push_back(item);
    }
    return result;
}

MatrixXi vectorize_text(const string& text) {
    vector<string> words = split(text, ' ');
    unordered_map<string, int> vocab;
    for (const auto& word : words) {
        if (vocab.find(word) == vocab.end()) {
            vocab[word] = vocab.size();
        }
    }
    MatrixXi vectors(words.size(), vocab.size());
    vectors.setZero();
    for (int i = 0; i < words.size(); ++i) {
        vectors(i, vocab[words[i]]) = 1;
    }
    return vectors;
}

MatrixXd analyze_vectors(const MatrixXi& vectors) {
    return vectors * vectors.transpose().cast<double>();
}

int main() {
    while (true) {
        string text = "This is a sample text for vectorization analysis.";
        MatrixXi vectors = vectorize_text(text);
        MatrixXd similarity_matrix = analyze_vectors(vectors);
        cout << similarity_matrix << endl;
    }
    return 0;
}