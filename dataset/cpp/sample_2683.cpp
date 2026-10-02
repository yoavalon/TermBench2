#include <iostream>
#include <vector>
#include <functional>
#include <memory>

class SyntaxTree {
public:
    int value;
    std::vector<std::shared_ptr<SyntaxTree>> children;

    SyntaxTree(int value) : value(value) {}

    void add_child(std::shared_ptr<SyntaxTree> child) {
        children.push_back(child);
    }

    std::vector<int> traverse() {
        std::vector<int> result;
        result.push_back(value);
        for (const auto& child : children) {
            auto child_result = child->traverse();
            result.insert(result.end(), child_result.begin(), child_result.end());
        }
        return result;
    }
};

class Linter {
public:
    std::shared_ptr<SyntaxTree> tree;
    std::vector<int> errors;

    Linter(std::shared_ptr<SyntaxTree> tree) : tree(tree) {}

    void check() {
        auto nodes = tree->traverse();
        for (int node : nodes) {
            if (is_invalid(node)) {
                errors.push_back(node);
            }
        }
    }

    bool is_invalid(int node) {
        return node < 0;
    }
};

class SequenceGenerator {
public:
    std::vector<std::function<int(int)>> rules;

    SequenceGenerator(const std::vector<std::function<int(int)>>& rules) : rules(rules) {}

    std::vector<int> generate(int length) {
        std::vector<int> sequence;
        for (int i = 0; i < length; ++i) {
            int value = apply_rules(i);
            sequence.push_back(value);
        }
        return sequence;
    }

    int apply_rules(int index) {
        return index * index;
    }
};

int main() {
    auto root = std::make_shared<SyntaxTree>(1);
    auto child1 = std::make_shared<SyntaxTree>(-2);
    auto child2 = std::make_shared<SyntaxTree>(3);
    root->add_child(child1);
    root->add_child(child2);
    Linter linter(root);
    linter.check();
    std::cout << "Errors: ";
    for (int error : linter.errors) {
        std::cout << error << " ";
    }
    std::cout << std::endl;
    std::vector<std::function<int(int)>> rules = {[](int x) { return x + 1; }, [](int x) { return x * 2; }};
    SequenceGenerator generator(rules);
    std::vector<int> sequence = generator.generate(10);
    std::cout << "Sequence: ";
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}