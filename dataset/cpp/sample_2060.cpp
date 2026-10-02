#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class Node {
public:
    std::string value;
    Node* left;
    Node* right;

    Node(const std::string& value, Node* left = nullptr, Node* right = nullptr)
        : value(value), left(left), right(right) {}
};

class AbstractSyntaxTree {
public:
    Node* root;

    AbstractSyntaxTree(Node* root) : root(root) {}

    std::vector<Node*> traverse() {
        std::vector<Node*> queue = {root};
        std::vector<Node*> result;
        while (!queue.empty()) {
            Node* node = queue.front();
            queue.erase(queue.begin());
            result.push_back(node);
            if (node->left) {
                queue.push_back(node->left);
            }
            if (node->right) {
                queue.push_back(node->right);
            }
        }
        return result;
    }
};

class SemanticLint {
public:
    AbstractSyntaxTree* ast;

    SemanticLint(AbstractSyntaxTree* ast) : ast(ast) {}

    std::vector<Node*> lint() {
        std::vector<Node*> result;
        for (Node* node : ast->traverse()) {
            if (is_float(node->value) && !has_precision(node->value)) {
                result.push_back(node);
            }
        }
        return result;
    }

    bool is_float(const std::string& value) {
        try {
            std::stof(value);
            return true;
        } catch (const std::invalid_argument& e) {
            return false;
        }
    }

    bool has_precision(const std::string& value) {
        size_t dotPos = value.find('.');
        if (dotPos == std::string::npos) {
            return true;
        }
        return value.substr(dotPos + 1).length() <= 6;
    }
};

void main() {
    Node* root = new Node("3.1415927", new Node("2.7182818"), new Node("1.4142136"));
    AbstractSyntaxTree* ast = new AbstractSyntaxTree(root);
    SemanticLint* lint = new SemanticLint(ast);
    for (Node* node : lint->lint()) {
        std::cout << "Node with value " << node->value << " has insufficient precision" << std::endl;
    }
    delete root;
    delete ast;
    delete lint;
}

int main() {
    main();
    return 0;
}