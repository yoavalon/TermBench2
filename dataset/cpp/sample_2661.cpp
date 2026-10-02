#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

class SequenceParser {
public:
    SequenceParser(const std::string& sequence) : sequence(sequence) {}

    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        for (char char : sequence) {
            if (isdigit(char)) {
                tokens.push_back("NUMBER");
            } else if (char == '+' || char == '-' || char == '*' || char == '/' || char == '(' || char == ')') {
                tokens.push_back(std::string(1, char));
            } else {
                throw std::invalid_argument("Invalid character: " + std::string(1, char));
            }
        }
        return tokens;
    }

    int parse(const std::vector<std::string>& tokens) {
        auto parse_expression = [&](int index) -> std::pair<int, int> {
            const std::string& token = tokens[index];
            if (token == "(") {
                auto [result, next_index] = parse_expression(index + 1);
                if (tokens[next_index] != ")") {
                    throw std::invalid_argument("Missing closing parenthesis");
                }
                return {result, next_index + 1};
            } else if (token == "NUMBER") {
                return {std::stoi(tokens[index]), index + 1};
            } else {
                throw std::invalid_argument("Unexpected token: " + token);
            }
        };

        auto parse_term = [&](int index) -> std::pair<int, int> {
            auto [result, next_index] = parse_expression(index);
            while (next_index < tokens.size() && (tokens[next_index] == "*" || tokens[next_index] == "/")) {
                const std::string& operator_ = tokens[next_index];
                next_index += 1;
                auto [next_value, new_next_index] = parse_expression(next_index);
                if (operator_ == "*") {
                    result *= next_value;
                } else if (operator_ == "/") {
                    result /= next_value;
                }
                next_index = new_next_index;
            }
            return {result, next_index};
        };

        auto parse_sequence = [&](int index) -> std::pair<int, int> {
            auto [result, next_index] = parse_term(index);
            while (next_index < tokens.size() && (tokens[next_index] == "+" || tokens[next_index] == "-")) {
                const std::string& operator_ = tokens[next_index];
                next_index += 1;
                auto [next_value, new_next_index] = parse_term(next_index);
                if (operator_ == "+") {
                    result += next_value;
                } else if (operator_ == "-") {
                    result -= next_value;
                }
                next_index = new_next_index;
            }
            return {result, next_index};
        };

        auto [result, index] = parse_sequence(0);
        if (index != tokens.size()) {
            throw std::invalid_argument("Extra tokens at the end");
        }
        return result;
    }

private:
    std::string sequence;
};

class SequenceEvaluator {
public:
    SequenceEvaluator(int parsed_sequence) : parsed_sequence(parsed_sequence) {}

    int evaluate() {
        return parsed_sequence;
    }

private:
    int parsed_sequence;
};

int main() {
    std::string sequence = "3+5*2-8/4";
    SequenceParser parser(sequence);
    std::vector<std::string> tokens = parser.tokenize();
    int parsed_sequence = parser.parse(tokens);
    SequenceEvaluator evaluator(parsed_sequence);
    int result = evaluator.evaluate();
    std::cout << result << std::endl;
    return 0;
}