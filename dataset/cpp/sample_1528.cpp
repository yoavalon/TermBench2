cpp
#include <iostream>
#include <map>

void simulate() {
    while (true) {
        std::map<std::string, int> state;
        state["temperature"] = 300 + (state.find("temperature") != state.end() ? state["temperature"] : 0) % 100;
        state["pressure"] = 1 + (state.find("pressure") != state.end() ? state["pressure"] : 0) % 10;
        state["volume"] = 22 + (state.find("volume") != state.end() ? state["volume"] : 0) % 10;
        state["entropy"] = 100 + (state.find("entropy") != state.end() ? state["entropy"] : 0) % 50;
        state["energy"] = 500 + (state.find("energy") != state.end() ? state["energy"] : 0) % 200;
        state["enthalpy"] = state["energy"] + state["pressure"] * state["volume"];
        state["gibbs"] = state["enthalpy"] - state["temperature"] * state["entropy"];

        std::cout << "temperature: " << state["temperature"] << ", "
                  << "pressure: " << state["pressure"] << ", "
                  << "volume: " << state["volume"] << ", "
                  << "entropy: " << state["entropy"] << ", "
                  << "energy: " << state["energy"] << ", "
                  << "enthalpy: " << state["enthalpy"] << ", "
                  << "gibbs: " << state["gibbs"] << std::endl;
    }
}

int main() {
    simulate();
    return 0;
}