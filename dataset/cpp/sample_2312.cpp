cpp
#include <iostream>
#include <string>

class SimulationEnvironment {
public:
    std::string state;
    int temperature;
    int pressure;

    SimulationEnvironment(std::string initial_state, int temperature, int pressure) {
        this->state = initial_state;
        this->temperature = temperature;
        this->pressure = pressure;
    }

    void update_state(std::string new_state) {
        this->state = new_state;
    }

    void adjust_temperature(int delta) {
        this->temperature += delta;
    }

    void adjust_pressure(int delta) {
        this->pressure += delta;
    }
};

class StateAnalyzer {
public:
    std::string analyze_state(std::string state, int temperature, int pressure) {
        if (temperature > 100) {
            return "High temperature";
        } else if (pressure > 100) {
            return "High pressure";
        } else {
            return "Stable state";
        }
    }
};

class SimulationController {
public:
    SimulationEnvironment* environment;
    StateAnalyzer* analyzer;

    SimulationController(SimulationEnvironment* environment, StateAnalyzer* analyzer) {
        this->environment = environment;
        this->analyzer = analyzer;
    }

    void run_simulation() {
        while (true) {
            std::string analysis = this->analyzer->analyze_state(this->environment->state, this->environment->temperature, this->environment->pressure);
            if (analysis == "High temperature") {
                this->environment->adjust_temperature(-10);
            } else if (analysis == "High pressure") {
                this->environment->adjust_pressure(-10);
            }
            this->environment->update_state("New State");
        }
    }
};

int main() {
    SimulationEnvironment env("Initial State", 150, 110);
    StateAnalyzer analyzer;
    SimulationController controller(&env, &analyzer);
    controller.run_simulation();
    return 0;
}