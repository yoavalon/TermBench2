#include <iostream>
#include <vector>
#include <string>

class SyntaxTree {
public:
    std::string value;
    std::vector<SyntaxTree> children;

    SyntaxTree(std::string value, std::vector<SyntaxTree> children = {}) : value(value), children(children) {}

    void add_child(const SyntaxTree& child) {
        children.push_back(child);
    }

    std::vector<std::string> validate() {
        std::vector<std::string> result;
        for (const auto& child : children) {
            result.insert(result.end(), child.validate().begin(), child.validate().end());
        }
        if (value == "FloatingPointOperation") {
            result.insert(result.end(), check_precision().begin(), check_precision().end());
        }
        return result;
    }

    std::vector<std::string> check_precision() {
        std::vector<std::string> issues;
        for (const auto& child : children) {
            if (child.value == "PrecisionLoss") {
                issues.push_back("Precision loss detected in " + value);
            }
        }
        return issues;
    }
};

class PrecisionChecker {
public:
    SyntaxTree tree;

    PrecisionChecker(const SyntaxTree& tree) : tree(tree) {}

    std::vector<std::string> lint() {
        return tree.validate();
    }
};

class ReportGenerator {
public:
    std::vector<std::string> issues;

    ReportGenerator(const std::vector<std::string>& issues) : issues(issues) {}

    std::string generate() {
        if (issues.empty()) {
            return "No precision issues detected.";
        }
        std::string report;
        for (const auto& issue : issues) {
            report += issue + "\n";
        }
        return report;
    }
};

void main() {
    SyntaxTree root("Program");
    SyntaxTree function("Function");
    SyntaxTree operation("FloatingPointOperation");
    SyntaxTree precision_loss("PrecisionLoss");
    operation.add_child(precision_loss);
    function.add_child(operation);
    root.add_child(function);
    PrecisionChecker checker(root);
    std::vector<std::string> issues = checker.lint();
    ReportGenerator reporter(issues);
    std::cout << reporter.generate();
}

int main() {
    main();
    return 0;
}