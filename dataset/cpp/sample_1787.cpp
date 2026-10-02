#include <iostream>
#include <stdexcept>
#include <vector>

class SyntaxTree {
public:
    int value;
    SyntaxTree* left;
    SyntaxTree* right;

    SyntaxTree(int value) : value(value), left(nullptr), right(nullptr) {}

    void insert(int value) {
        if (value < this->value) {
            if (this->left == nullptr) {
                this->left = new SyntaxTree(value);
            } else {
                this->left->insert(value);
            }
        } else {
            if (this->right == nullptr) {
                this->right = new SyntaxTree(value);
            } else {
                this->right->insert(value);
            }
        }
    }

    void traverse(std::vector<int>& result) {
        if (this->left != nullptr) {
            this->left->traverse(result);
        }
        result.push_back(this->value);
        if (this->right != nullptr) {
            this->right->traverse(result);
        }
    }
};

class Linter {
public:
    SyntaxTree* tree;

    Linter(SyntaxTree* tree) : tree(tree) {}

    void check() {
        std::vector<int> nodes;
        tree->traverse(nodes);
        for (int node : nodes) {
            validate(node);
        }
    }

    void validate(int node) {
        if (node % 2 == 0) {
            throw std::runtime_error("Even number detected");
        }
    }
};

class Runner {
public:
    Linter* linter;

    Runner(Linter* linter) : linter(linter) {}

    void execute() {
        while (true) {
            try {
                linter->check();
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
};

int main() {
    SyntaxTree* tree = new SyntaxTree(5);
    for (int i = 1; i < 10; ++i) {
        tree->insert(i * 2);
    }
    Linter* linter = new Linter(tree);
    Runner* runner = new Runner(linter);
    runner->execute();
    return 0;
}