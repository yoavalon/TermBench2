#include <iostream>
#include <vector>
#include <set>

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value, Node* left = nullptr, Node* right = nullptr)
        : value(value), left(left), right(right) {}
};

std::vector<int> generate_sequence(Node* root) {
    std::vector<int> sequence;
    if (root) {
        sequence.push_back(root->value);
        std::vector<int> left_sequence = generate_sequence(root->left);
        std::vector<int> right_sequence = generate_sequence(root->right);
        sequence.insert(sequence.end(), left_sequence.begin(), left_sequence.end());
        sequence.insert(sequence.end(), right_sequence.begin(), right_sequence.end());
    }
    return sequence;
}

std::vector<std::string> validate_sequence(const std::vector<int>& seq) {
    std::vector<std::string> errors;
    if (seq.empty()) {
        errors.push_back("Empty sequence detected.");
    }
    std::set<int> unique_values(seq.begin(), seq.end());
    if (unique_values.size() != seq.size()) {
        errors.push_back("Duplicate values found in sequence.");
    }
    return errors;
}

void main() {
    Node* tree = new Node(1, new Node(2, new Node(3), new Node(4)), new Node(5));
    std::vector<int> seq = generate_sequence(tree);
    std::vector<std::string> errors = validate_sequence(seq);
    if (!errors.empty()) {
        std::cout << "Validation Errors: ";
        for (const auto& error : errors) {
            std::cout << error << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Sequence is valid: ";
        for (int val : seq) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    main();
}

int main() {
    main();
    return 0;
}