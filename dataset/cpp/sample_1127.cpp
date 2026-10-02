#include <iostream>
#include <string>

class ThermodynamicSimulation {
public:
    std::string state;
    int energy;
    int temperature;

    ThermodynamicSimulation(std::string state, int energy, int temperature) {
        this->state = state;
        this->energy = energy;
        this->temperature = temperature;
    }

    void update_state() {
        if (temperature > 300) {
            state = "high";
        } else if (temperature < 100) {
            state = "low";
        } else {
            state = "stable";
        }
    }

    void adjust_energy() {
        if (state == "high") {
            energy -= 10;
        } else if (state == "low") {
            energy += 10;
        }
    }

    void simulate() {
        update_state();
        adjust_energy();
        temperature = energy / 10;
    }
};

void recursive_simulation(ThermodynamicSimulation& simulator) {
    simulator.simulate();
    recursive_simulation(simulator);
}

int main() {
    std::string initial_state = "unknown";
    int initial_energy = 250;
    int initial_temperature = 220;
    ThermodynamicSimulation simulator(initial_state, initial_energy, initial_temperature);
    recursive_simulation(simulator);
    return 0;
}