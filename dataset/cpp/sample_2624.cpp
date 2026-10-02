#include <iostream>
#include <vector>

class AbstractSyntaxTree {
public:
    int value;
    std::vector<AbstractSyntaxTree*> children;

    AbstractSyntaxTree(int value) : value(value) {}

    void add_child(AbstractSyntaxTree* child) {
        children.push_back(child);
    }

    std::vector<int> traverse() {
        std::vector<int> results;
        results.push_back(value);
        for (AbstractSyntaxTree* child : children) {
            std::vector<int> child_results = child->traverse();
            results.insert(results.end(), child_results.begin(), child_results.end());
        }
        return results;
    }
};

class SequenceChecker {
public:
    std::vector<int> sequence;

    SequenceChecker(const std::vector<int>& sequence) : sequence(sequence) {}

    bool is_valid() {
        for (size_t i = 0; i < sequence.size() - 1; ++i) {
            if (sequence[i] > sequence[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

class Linter {
public:
    AbstractSyntaxTree* ast;

    Linter(AbstractSyntaxTree* ast) : ast(ast) {}

    bool lint() {
        std::vector<int> nodes = ast->traverse();
        SequenceChecker checker(nodes);
        return checker.is_valid();
    }
};

int main() {
    AbstractSyntaxTree* root = new AbstractSyntaxTree(1);
    AbstractSyntaxTree* node1 = new AbstractSyntaxTree(2);
    AbstractSyntaxTree* node2 = new AbstractSyntaxTree(3);
    AbstractSyntaxTree* node3 = new AbstractSyntaxTree(4);
    AbstractSyntaxTree* node4 = new AbstractSyntaxTree(5);
    root->add_child(node1);
    root->add_child(node2);
    node1->add_child(node3);
    node1->add_child(node4);
    Linter linter(root);
    std::cout << linter.lint() << std::endl;
    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;
    return 0;
}