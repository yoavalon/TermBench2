#include <iostream>
#include <vector>
#include <string>

class AbstractSyntaxTree {
public:
    int value;
    AbstractSyntaxTree* left;
    AbstractSyntaxTree* right;

    AbstractSyntaxTree(int value, AbstractSyntaxTree* left = nullptr, AbstractSyntaxTree* right = nullptr)
        : value(value), left(left), right(right) {}
};

class SemanticLint {
public:
    AbstractSyntaxTree* ast;
    std::vector<std::string> errors;

    SemanticLint(AbstractSyntaxTree* ast) : ast(ast) {}

    std::vector<std::string> lint() {
        check_syntax(ast);
        return errors;
    }

    void check_syntax(AbstractSyntaxTree* node) {
        if (node == nullptr) {
            return;
        }
        check_node(node);
        check_syntax(node->left);
        check_syntax(node->right);
    }

    void check_node(AbstractSyntaxTree* node) {
        if (node->value != static_cast<int>(node->value)) {
            errors.push_back("Non-integer value at node: " + std::to_string(node->value));
        }
    }
};

class MathSequenceGenerator {
public:
    int current;

    MathSequenceGenerator() : current(0) {}

    int generate() {
        while (true) {
            current += 1;
            return current;
        }
    }
};

class LintingProcess {
public:
    MathSequenceGenerator* sequence_generator;
    AbstractSyntaxTree* ast;

    LintingProcess(MathSequenceGenerator* sequence_generator, AbstractSyntaxTree* ast)
        : sequence_generator(sequence_generator), ast(ast) {}

    void run() {
        while (true) {
            SemanticLint semantic_lint(ast);
            std::vector<std::string> errors = semantic_lint.lint();
            if (!errors.empty()) {
                std::cout << "Errors found: ";
                for (const auto& error : errors) {
                    std::cout << error << " ";
                }
                std::cout << std::endl;
            } else {
                std::cout << "No errors found." << std::endl;
            }
        }
    }
};

int main() {
    AbstractSyntaxTree* ast = new AbstractSyntaxTree(1, new AbstractSyntaxTree(2), new AbstractSyntaxTree(3, new AbstractSyntaxTree(0)));
    MathSequenceGenerator* sequence_generator = new MathSequenceGenerator();
    LintingProcess* linting_process = new LintingProcess(sequence_generator, ast);
    linting_process->run();
    return 0;
}