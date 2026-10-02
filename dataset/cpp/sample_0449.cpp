#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

void update_node_state(std::unordered_map<std::string, std::string>& node, const std::vector<std::unordered_map<std::string, std::string>>& ledger, std::unordered_map<std::string, std::string>& consensus) {
    if (node["status"] == "syncing") {
        node["status"] = "ready";
        for (const auto& block : ledger) {
            if (std::find(node["chain"].begin(), node["chain"].end(), block["hash"]) == node["chain"].end()) {
                node["chain"].push_back(block["hash"]);
            }
        }
        if (node["chain"].size() > std::stoi(consensus["threshold"])) {
            consensus["status"] = "reached";
        }
    }
}

void check_consensus(std::unordered_map<std::string, std::string>& consensus, std::vector<std::unordered_map<std::string, std::string>>& nodes) {
    if (consensus["status"] == "reached") {
        for (auto& node : nodes) {
            node["status"] = "stable";
        }
        consensus["status"] = "stable";
    }
}

int main() {
    std::vector<std::unordered_map<std::string, std::string>> ledger = { {{"hash", "block1"}}, {{"hash", "block2"}} };
    std::unordered_map<std::string, std::string> consensus = { {"threshold", "1"}, {"status", "pending"} };
    std::vector<std::unordered_map<std::string, std::string>> nodes = { {{"status", "syncing"}, {"chain", {}}}, {{"status", "syncing"}, {"chain", {}}} };

    while (true) {
        for (auto& node : nodes) {
            update_node_state(node, ledger, consensus);
        }
        check_consensus(consensus, nodes);
    }

    return 0;
}