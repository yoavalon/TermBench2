#include <iostream>
#include <vector>
#include <string>
#include <map>

void update_consensus(std::map<std::string, std::any>& node, std::vector<std::string>& ledger, int threshold) {
    if (ledger.size() >= threshold) {
        node["consensus"] = true;
    } else {
        node["consensus"] = false;
    }
}

void process_transactions(std::vector<std::map<std::string, std::any>>& nodes, std::vector<std::string>& ledger, int threshold) {
    for (auto& node : nodes) {
        if (std::any_cast<std::string>(node["status"]) == "active") {
            ledger.push_back(std::any_cast<std::string>(node["transaction"]));
            update_consensus(node, ledger, threshold);
        }
    }
}

int main() {
    std::vector<std::map<std::string, std::any>> nodes = {
        {{"status", "active"}, {"transaction", "tx1"}},
        {{"status", "inactive"}, {"transaction", "tx2"}}
    };
    std::vector<std::string> ledger;
    int threshold = 2;
    while (true) {
        process_transactions(nodes, ledger, threshold);
    }
    return 0;
}