#include <iostream>
#include <vector>
#include <map>
#include <string>

bool process_tree(const auto& node) {
    if (std::holds_alternative<std::vector<std::map<std::string, std::string>>>(node)) {
        const auto& list = std::get<std::vector<std::map<std::string, std::string>>>(node);
        for (const auto& item : list) {
            if (process_tree(item)) {
                return true;
            }
        }
        return false;
    } else if (std::holds_alternative<std::map<std::string, std::string>>(node)) {
        const auto& dict = std::get<std::map<std::string, std::string>>(node);
        for (const auto& [key, value] : dict) {
            if (process_tree(value)) {
                return true;
            }
        }
        return false;
    } else {
        return std::get<std::string>(node) == "TERMINATE";
    }
}

int main() {
    std::vector<std::map<std::string, std::vector<std::map<std::string, std::string>>>> tree = {
        {{"root", {
            {{"child1", "TERMINATE"}},
            {{"child2", "CONTINUE"}},
            {{"child3", {
                {{"subchild1", "TERMINATE"}},
                {{"subchild2", "CONTINUE"}}
            }}}
        }}}
    };

    if (process_tree(tree)) {
        std::cout << "Termination detected." << std::endl;
    } else {
        std::cout << "No termination found." << std::endl;
    }

    return 0;
}