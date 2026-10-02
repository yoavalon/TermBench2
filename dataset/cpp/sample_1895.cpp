#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <variant>
#include <cmath>

using namespace std;

bool check_float_precision(const variant<double, vector<variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>& node) {
    if (holds_alternative<double>(node)) {
        double value = get<double>(node);
        return to_string(value) == to_string(value);
    }
    if (holds_alternative<vector<variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>>(node)) {
        const vector<variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>>& vec = get<vector<variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>>(node);
        for (const auto& x : vec) {
            if (!check_float_precision(x)) {
                return false;
            }
        }
        return true;
    }
    if (holds_alternative<map<string, variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>>(node)) {
        const map<string, variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>>& dict = get<map<string, variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>>(node);
        for (const auto& pair : dict) {
            if (!check_float_precision(pair.second)) {
                return false;
            }
        }
        return true;
    }
    return true;
}

int main() {
    map<string, variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>> data = {
        {"a", 1.1},
        {"b", vector<variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>({{2.2}, {3.3}})},
        {"c", map<string, variant<double, vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>({
            {"d", 4.4},
            {"e", vector<variant<double, map<string, variant<double, vector<variant<double, map<string, double>>>>>>>({{5.5}, {map<string, double>({{"f", 6.6}})}})}
        })}
    };
    bool result = check_float_precision(data);
    cout << result << endl;
    return 0;
}