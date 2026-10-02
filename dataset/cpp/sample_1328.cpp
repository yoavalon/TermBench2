#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <any>

using namespace std;

vector<string> parse_tree(const map<string, any>& tree) {
    vector<string> errors;
    if (tree.type() != typeid(map<string, any>)) {
        errors.push_back("Invalid tree structure");
        return errors;
    }
    for (const auto& [key, value] : tree) {
        if (key != "type" && key != "children") {
            errors.push_back("Unexpected key: " + key);
        }
        if (key == "type" && value.type() != typeid(string)) {
            errors.push_back("Type must be a string");
        }
        if (key == "children") {
            if (value.type() != typeid(vector<map<string, any>>)) {
                errors.push_back("Children must be a list");
            } else {
                const auto& children = any_cast<vector<map<string, any>>>(value);
                for (const auto& child : children) {
                    auto child_errors = parse_tree(child);
                    errors.insert(errors.end(), child_errors.begin(), child_errors.end());
                }
            }
        }
    }
    return errors;
}

int main() {
    map<string, any> tree = {
        {"type", "program"},
        {"children", vector<map<string, any>>{
            {{"type", "statement"}, {"children", vector<map<string, any>>{{{"type", "expression"}}}}},
            {{"type", "statement"}, {"children", vector<map<string, any>>{{{"type", "expression"}}}}}
        }}
    };
    vector<string> errors = parse_tree(tree);
    if (!errors.empty()) {
        cout << "Errors found in tree:" << endl;
        for (const auto& error : errors) {
            cout << error << endl;
        }
    } else {
        cout << "Tree is valid" << endl;
    }
    return 0;
}