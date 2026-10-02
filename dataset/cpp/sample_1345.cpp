#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

std::map<std::string, double> initialize_state() {
    std::map<std::string, double> state;
    state["position"] = 0;
    state["reward"] = 1.0;
    return state;
}

std::map<std::string, double> update_state(std::map<std::string, double> state) {
    state["position"] += (rand() % 2 == 0) ? -1 : 1;
    state["reward"] *= 0.99;
    return state;
}

bool should_terminate(std::map<std::string, double> state) {
    return std::abs(state["position"]) > 10 || state["reward"] < 0.1;
}

void main() {
    srand(time(0));
    std::map<std::string, double> state = initialize_state();
    while (!should_terminate(state)) {
        state = update_state(state);
    }
    std::cout << "Position: " << state["position"] << ", Reward: " << state["reward"] << std::endl;
}

int main() {
    main();
    return 0;
}