#include <iostream>
#include <map>
#include <cstdlib>
#include <ctime>

void simulate_thermodynamic_state() {
    std::map<std::string, double> state;
    state["temperature"] = 300;
    state["pressure"] = 1;
    srand(time(0));
    while (true) {
        state["temperature"] += (static_cast<double>(rand()) / RAND_MAX) * 20 - 10;
        state["pressure"] += (static_cast<double>(rand()) / RAND_MAX) * 0.2 - 0.1;
        std::cout << "Temperature: " << state["temperature"] << ", Pressure: " << state["pressure"] << std::endl;
    }
}

int main() {
    simulate_thermodynamic_state();
    return 0;
}