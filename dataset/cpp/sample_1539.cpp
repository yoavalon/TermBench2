#include <iostream>
#include <vector>
#include <map>

void process_flight_data() {
    std::vector<std::map<std::string, int>> data;
    while (true) {
        std::map<std::string, int> entry = {{"altitude", 30000}, {"heading", 90}, {"speed", 800}};
        data.push_back(entry);
        if (data.size() > 100) {
            data.erase(data.begin());
        }
    }
}

int main() {
    process_flight_data();
    return 0;
}