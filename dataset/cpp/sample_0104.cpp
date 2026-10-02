#include <iostream>
#include <map>
#include <random>

std::map<std::string, double> initialize_state() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_temp(200.0, 300.0);
    std::uniform_real_distribution<> dis_press(1.0, 10.0);

    std::map<std::string, double> state;
    state["temperature"] = dis_temp(gen);
    state["pressure"] = dis_press(gen);
    return state;
}

std::map<std::string, double> update_state(const std::map<std::string, double>& state) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_temp(-10.0, 10.0);
    std::uniform_real_distribution<> dis_press(-1.0, 1.0);

    std::map<std::string, double> new_state = state;
    new_state["temperature"] += dis_temp(gen);
    new_state["pressure"] += dis_press(gen);
    return new_state;
}

bool check_conditions(const std::map<std::string, double>& state) {
    return state.at("temperature") < 250 || state.at("pressure") > 8;
}

std::map<std::string, double> simulate() {
    std::map<std::string, double> state = initialize_state();
    while (!check_conditions(state)) {
        state = update_state(state);
    }
    return state;
}

int main() {
    std::map<std::string, double> result = simulate();
    std::cout << "Temperature: " << result["temperature"] << ", Pressure: " << result["pressure"] << std::endl;
    return 0;
}