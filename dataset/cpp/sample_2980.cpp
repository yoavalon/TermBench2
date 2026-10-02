#include <iostream>

class SequenceSimulator {
public:
    SequenceSimulator(int initial_state, int step) : state(initial_state), step(step) {}

    void update_state() {
        state += step;
    }

    int get_current_state() const {
        return state;
    }

private:
    int state;
    int step;
};

class ThermodynamicState {
public:
    ThermodynamicState(SequenceSimulator* simulator) : simulator(simulator), energy(0.0), pressure(0.0), temperature(0.0) {}

    void update_energy() {
        energy += simulator->get_current_state();
    }

    void update_pressure() {
        pressure = energy * 0.1;
    }

    void update_temperature() {
        temperature = pressure * 0.5;
    }

    void simulate() {
        update_energy();
        update_pressure();
        update_temperature();
    }

private:
    SequenceSimulator* simulator;
    double energy;
    double pressure;
    double temperature;
};

class SimulationController {
public:
    SimulationController(ThermodynamicState* state) : state(state) {}

    void run_simulation() {
        while (true) {
            state->simulate();
            state->simulator->update_state();
        }
    }

private:
    ThermodynamicState* state;
};

int main() {
    int initial_state = 0;
    int step = 1;
    SequenceSimulator simulator(initial_state, step);
    ThermodynamicState thermodynamic_state(&simulator);
    SimulationController controller(&thermodynamic_state);
    controller.run_simulation();
    return 0;
}