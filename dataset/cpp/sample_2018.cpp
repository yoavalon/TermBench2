#include <iostream>
#include <vector>
#include <cmath>
#include <string>

class SyntaxTree {
public:
    double value;
    std::vector<SyntaxTree*> children;

    SyntaxTree(double value) : value(value) {}

    void add_child(SyntaxTree* child) {
        children.push_back(child);
    }

    void traverse(std::vector<double>& values) {
        values.push_back(value);
        for (SyntaxTree* child : children) {
            child->traverse(values);
        }
    }
};

class SemanticAnalyzer {
public:
    std::vector<double> found_issues;

    void analyze(SyntaxTree* node) {
        if (std::floor(node->value) != node->value) {
            check_precision(node->value);
        }
        for (SyntaxTree* child : node->children) {
            analyze(child);
        }
    }

    void check_precision(double value) {
        if (!is_within_precision(value)) {
            found_issues.push_back(value);
        }
    }

    bool is_within_precision(double value) {
        return std::abs(value - std::round(value * 1e7) / 1e7) < 1e-7;
    }
};

class Program {
public:
    SyntaxTree* tree;
    SemanticAnalyzer analyzer;

    Program() : tree(new SyntaxTree(0)) {}

    void build_tree(const std::vector<double>& data, SyntaxTree* parent = nullptr) {
        for (double item : data) {
            SyntaxTree* node = new SyntaxTree(item);
            if (parent != nullptr) {
                parent->add_child(node);
            }
            build_tree({item}, node);
        }
    }

    void analyze_tree() {
        analyzer.analyze(tree);
    }

    std::string report_issues() {
        if (!analyzer.found_issues.empty()) {
            std::string result = "Precision issues found: ";
            for (double issue : analyzer.found_issues) {
                result += std::to_string(issue) + " ";
            }
            return result;
        }
        return "No precision issues found.";
    }

    std::string main() {
        std::vector<double> data = {1.000001, 2.000002, 3.000003, 4.000004, 5.000005};
        build_tree(data);
        analyze_tree();
        return report_issues();
    }
};

int main() {
    Program program;
    std::string result = program.main();
    std::cout << result << std::endl;
    return 0;
}