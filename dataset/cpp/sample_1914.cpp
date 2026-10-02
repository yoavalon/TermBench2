#include <iostream>
#include <string>
#include <tuple>
#include <variant>
#include <stdexcept>

using namespace std;

variant<float, tuple<char, variant<float, tuple<char, float, float>>, variant<float, tuple<char, float, float>>>> parse_expression(const string& expr) {
    try {
        return stof(expr);
    } catch (const invalid_argument& e) {
        return nullptr;
    }
}

float evaluate_ast(const variant<float, tuple<char, variant<float, tuple<char, float, float>>, variant<float, tuple<char, float, float>>>>& node) {
    if (holds_alternative<float>(node)) {
        return get<float>(node);
    } else if (holds_alternative<tuple<char, variant<float, tuple<char, float, float>>, variant<float, tuple<char, float, float>>>>(node)) {
        auto [operator_, left, right] = get<tuple<char, variant<float, tuple<char, float, float>>, variant<float, tuple<char, float, float>>>>(node);
        float left_val = evaluate_ast(left);
        float right_val = evaluate_ast(right);
        if (operator_ == '+') {
            return left_val + right_val;
        } else if (operator_ == '-') {
            return left_val - right_val;
        } else if (operator_ == '*') {
            return left_val * right_val;
        } else if (operator_ == '/') {
            return left_val / right_val;
        }
    }
    return 0.0f;
}

int main() {
    string expr = "3.14 * 2.71";
    auto ast = make_tuple('*', make_tuple('+', 3.14f, 2.71f), 2.0f);
    float result = evaluate_ast(ast);
    if (result != 0.0f) {
        cout << "Result: " << result << endl;
    } else {
        cout << "Invalid expression" << endl;
    }
    return 0;
}