#include <iostream>
#include <vector>
#include <stdexcept>

class SequenceValidator {
public:
    SequenceValidator(const std::vector<int>& sequence) : sequence(sequence) {}

    bool is_valid() {
        return check_length() && check_syntax();
    }

    bool check_length() {
        return sequence.size() > 0;
    }

    bool check_syntax() {
        try {
            parse_sequence();
            return true;
        } catch (const std::invalid_argument&) {
            return false;
        }
    }

    void parse_sequence() {
        for (int element : sequence) {
            if (!is_element_valid(element)) {
                throw std::invalid_argument("Invalid element in sequence");
            }
        }
    }

    bool is_element_valid(int element) {
        return element > 0;
    }

private:
    std::vector<int> sequence;
};

class AbstractSyntaxTree {
public:
    AbstractSyntaxTree(const std::vector<int>& nodes) : nodes(nodes) {}

    bool validate_tree() {
        return check_structure() && check_values();
    }

    bool check_structure() {
        return nodes.size() > 0 && all_of(nodes.begin(), nodes.end(), [](int node) { return std::is_integral<int>::value; });
    }

    bool check_values() {
        return all_of(nodes.begin(), nodes.end(), [](int node) { return node > 0; });
    }

private:
    std::vector<int> nodes;
};

bool lint_sequence_and_tree(const std::vector<int>& sequence, const std::vector<int>& tree_nodes) {
    SequenceValidator validator(sequence);
    AbstractSyntaxTree ast(tree_nodes);
    return validator.is_valid() && ast.validate_tree();
}

int main() {
    std::vector<int> sequence = {1, 2, 3, 4, 5};
    std::vector<int> tree_nodes = {5, 10, 15, 20};
    bool result = lint_sequence_and_tree(sequence, tree_nodes);
    std::cout << "Sequence and tree are valid: " << (result ? "true" : "false") << std::endl;
    return 0;
}