#include <iostream>
#include <vector>
#include <map>

void update_state(std::map<std::string, int>& state, std::map<std::string, std::string>& frame) {
    state["frame"] += 1;
    state["data"].push_back(frame["value"]);
}

bool check_boundary_conditions(const std::map<std::string, int>& state, int max_frames) {
    if (state.at("frame") >= max_frames) {
        return true;
    }
    return false;
}

int main() {
    int max_frames = 10;
    std::map<std::string, int> state = {{"frame", 0}};
    std::map<std::string, std::vector<std::string>> state_data = {{"data", std::vector<std::string>()}};
    while (!check_boundary_conditions(state, max_frames)) {
        std::map<std::string, std::string> frame = {{"id", std::to_string(state["frame"])}, {"value", "data_frame"}};
        update_state(state, frame);
    }
    std::cout << "frame: " << state["frame"] << std::endl;
    for (const auto& data : state_data["data"]) {
        std::cout << "data: " << data << std::endl;
    }
    return 0;
}