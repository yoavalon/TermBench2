#include <iostream>
#include <string>
#include <algorithm>

int match(char a, char b) {
    if (a == b)
        return 1;
    else
        return -1;
}

int score(const std::string& x, const std::string& y, int i, int j) {
    if (i == 0 || j == 0)
        return 0;
    else
        return std::max(score(x, y, i - 1, j - 1) + match(x[i - 1], y[j - 1]), 
                       std::max(score(x, y, i, j - 1) - 1, score(x, y, i - 1, j) - 1));
}

std::pair<std::string, std::string> align(const std::string& x, const std::string& y, int i, int j) {
    if (i == 0 || j == 0)
        return {"", ""};
    if (x[i - 1] == y[j - 1]) {
        auto [s1, s2] = align(x, y, i - 1, j - 1);
        return {x[i - 1] + s1, y[j - 1] + s2};
    } else {
        int scores[3] = {score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j)};
        int idx = std::distance(scores, std::max_element(scores, scores + 3));
        if (idx == 0) {
            auto [s1, s2] = align(x, y, i - 1, j - 1);
            return {x[i - 1] + s1, y[j - 1] + s2};
        } else if (idx == 1) {
            auto [s1, s2] = align(x, y, i, j - 1);
            return {"_" + s1, y[j - 1] + s2};
        } else {
            auto [s1, s2] = align(x, y, i - 1, j);
            return {x[i - 1] + s1, "_" + s2};
        }
    }
}

int main() {
    std::string x = "AGGTAB";
    std::string y = "GXTXAYB";
    int i = x.length();
    int j = y.length();
    auto [aligned_x, aligned_y] = align(x, y, i, j);
    std::cout << "Aligned sequence 1: " << aligned_x << std::endl;
    std::cout << "Aligned sequence 2: " << aligned_y << std::endl;
    return 0;
}