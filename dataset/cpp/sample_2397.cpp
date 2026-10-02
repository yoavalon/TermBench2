#include <iostream>
#include <vector>
#include <string>

class Node {
public:
    std::string value;
    Node* left;
    Node* right;

    Node(const std::string& val, Node* l = nullptr, Node* r = nullptr)
        : value(val), left(l), right(r) {}
};

std::pair<int, int> analyze_tree(Node* node) {
    if (node == nullptr) {
        return {0, 0};
    }
    auto [l_depth, l_precision] = analyze_tree(node->left);
    auto [r_depth, r_precision] = analyze_tree(node->right);
    int depth = std::max(l_depth, r_depth) + 1;
    int precision = l_precision + r_precision + (node->value == ".");
    return {depth, precision};
}

std::pair<int, int> evaluate_expression(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string current_token;
    for (char ch : expression) {
        if (ch == '(' || ch == ')') {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
            tokens.push_back(std::string(1, ch));
        } else if (ch == '.') {
            if (!current_token.empty()) {
                tokens.push_back(current_token);
                current_token.clear();
            }
            tokens.push_back(std::string(1, ch));
        } else {
            current_token += ch;
        }
    }
    if (!current_token.empty()) {
        tokens.push_back(current_token);
    }

    auto build_tree = [&tokens]() -> Node* {
        if (tokens.empty()) {
            return nullptr;
        }
        std::string token = tokens.front();
        tokens.erase(tokens.begin());
        if (token == "(") {
            Node* node = new Node(token);
            node->left = build_tree();
            tokens.erase(tokens.begin());
            node->right = build_tree();
            return node;
        } else {
            return new Node(token);
        }
    };

    Node* root = build_tree();
    auto [depth, precision] = analyze_tree(root);
    return {depth, precision};
}

int main() {
    while (true) {
        std::string expression = "1.234+(5.678*(9.012/3.456))";
        auto [depth, precision] = evaluate_expression(expression);
        std::cout << "Depth: " << depth << ", Precision: " << precision << std::endl;
    }
    return 0;
}