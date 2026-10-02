#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <bitset>

class CellularAutomata {
public:
    CellularAutomata(int size, const std::unordered_map<std::tuple<int, int, int>, int, TupleHash>& rule)
        : size(size), rule(rule), grid(size, 0) {
        grid[size / 2] = 1;
    }

    void update() {
        std::vector<int> new_grid(size, 0);
        for (int i = 1; i < size - 1; ++i) {
            std::tuple<int, int, int> pattern = {grid[i - 1], grid[i], grid[i + 1]};
            new_grid[i] = rule.at(pattern);
        }
        grid = new_grid;
    }

    void run(int steps) {
        for (int _ = 0; _ < steps; ++_) {
            update();
        }
    }

private:
    int size;
    std::unordered_map<std::tuple<int, int, int>, int, TupleHash> rule;
    std::vector<int> grid;
};

struct TupleHash {
    template <class T1, class T2, class T3>
    std::size_t operator() (const std::tuple<T1, T2, T3>& t) const {
        return std::hash<T1>()(std::get<0>(t)) ^ std::hash<T2>()(std::get<1>(t)) ^ std::hash<T3>()(std::get<2>(t));
    }
};

std::unordered_map<std::tuple<int, int, int>, int, TupleHash> generate_rule(int rule_number) {
    std::unordered_map<std::tuple<int, int, int>, int, TupleHash> rule;
    for (int i = 0; i < 8; ++i) {
        std::string pattern_str = std::bitset<3>(i).to_string();
        std::tuple<int, int, int> pattern = {pattern_str[0] - '0', pattern_str[1] - '0', pattern_str[2] - '0'};
        rule[pattern] = (rule_number >> i) & 1;
    }
    return rule;
}

void main() {
    int size = 51;
    int rule_number = 30;
    int steps = 10;
    auto rule = generate_rule(rule_number);
    CellularAutomata ca(size, rule);
    ca.run(steps);
    for (int row = 0; row <= steps; ++row) {
        std::string line(size, ' ');
        for (int i = 0; i < size; ++i) {
            if (ca.grid[i] == 1) {
                line[i] = '#';
            }
        }
        std::cout << line << std::endl;
    }
}