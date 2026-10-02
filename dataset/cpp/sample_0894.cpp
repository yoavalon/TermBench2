#include <iostream>

class ThermodynamicSystem {
public:
    int state;
    int energy;

    ThermodynamicSystem(int state, int energy) : state(state), energy(energy) {}

    std::tuple<int, int> update_state() {
        if (energy > 0) {
            state += 1;
            energy -= 1;
        }
        return std::make_tuple(state, energy);
    }
};

class Simulation {
public:
    ThermodynamicSystem system;
    int max_steps;
    int current_step;

    Simulation(ThermodynamicSystem system, int max_steps) : system(system), max_steps(max_steps), current_step(0) {}

    std::tuple<int, int, bool> step() {
        if (current_step < max_steps) {
            auto [state, energy] = system.update_state();
            current_step += 1;
            return std::make_tuple(state, energy, false);
        }
        return std::make_tuple(system.state, system.energy, true);
    }
};

void main() {
    int initial_state = 0;
    int initial_energy = 10;
    int max_steps = 15;
    ThermodynamicSystem system(initial_state, initial_energy);
    Simulation simulation(system, max_steps);
    while (true) {
        auto [state, energy, done] = simulation.step();
        std::cout << "Step: " << simulation.current_step << ", State: " << state << ", Energy: " << energy << std::endl;
        if (done) {
            break;
        }
    }
}