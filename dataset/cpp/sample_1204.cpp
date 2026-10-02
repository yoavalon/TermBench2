#include <iostream>
#include <vector>
#include <string>
#include <map>

struct FlightData {
    int id;
    int altitude;
    std::string trajectory;
};

void process_flight_data() {
    std::vector<FlightData> data = {
        {1, 30000, "constant"},
        {2, 35000, "ascending"},
        {3, 32000, "descending"},
        {4, 33000, "constant"},
        {5, 31000, "ascending"}
    };
    for (auto& entry : data) {
        if (entry.trajectory == "ascending") {
            entry.altitude += 1000;
        } else if (entry.trajectory == "descending") {
            entry.altitude -= 500;
        }
    }
    for (const auto& entry : data) {
        std::cout << "Flight " << entry.id << ": Altitude " << entry.altitude << ", Trajectory " << entry.trajectory << std::endl;
    }
}

int main() {
    process_flight_data();
    return 0;
}