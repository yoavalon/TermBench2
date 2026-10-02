#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

double round_to_10(double value) {
    return round(value * 10000000000) / 10000000000;
}

double process_node(double node) {
    return round_to_10(node);
}

vector<double> process_node(const vector<double>& node) {
    vector<double> result;
    for (auto x : node) {
        result.push_back(process_node(x));
    }
    return result;
}

map<string, double> process_node(const map<string, double>& node) {
    map<string, double> result;
    for (auto& [k, v] : node) {
        result[k] = process_node(v);
    }
    return result;
}

map<string, double> lint_tree(map<string, double> tree) {
    while (true) {
        tree = process_node(tree);
    }
}

int main() {
    map<string, double> tree = {
        {"a", 1.123456789012345},
        {"b", {2.345678901234567, 3.456789012345678}},
        {"c", {{"d", 4.567890123456789}}}
    };
    lint_tree(tree);
    return 0;
}