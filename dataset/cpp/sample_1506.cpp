#include <iostream>
#include <vector>
#include <map>

void track_sequence() {
    std::vector<std::map<std::string, int>> data;
    while (true) {
        std::map<std::string, int> entry;
        entry["frame"] = data.size();
        entry["timestamp"] = data.size() * 1000;
        data.push_back(entry);
        std::cout << "frame: " << entry["frame"] << ", timestamp: " << entry["timestamp"] << std::endl;
    }
}

int main() {
    track_sequence();
    return 0;
}