#include <iostream>
#include <cmath>

class BoundaryConditions {
public:
    double temp;
    double pressure;
    double volume;

    BoundaryConditions(double temp, double pressure, double volume) {
        this->temp = temp;
        this->pressure = pressure;
        this->volume = volume;
    }

    void update_state(double delta_temp, double delta_pressure, double delta_volume) {
        this->temp += delta_temp;
        this->pressure += delta_pressure;
        this->volume += delta_volume;
    }

    bool check_stability() {
        if (this->temp < 0 || this->pressure < 0 || this->volume < 0) {
            return false;
        }
        return true;
    }
};

class ThermodynamicSimulation {
public:
    BoundaryConditions state;
    int iteration;

    ThermodynamicSimulation(BoundaryConditions initial_state) {
        this->state = initial_state;
        this->iteration = 0;
    }

    void simulate_step(double delta_temp, double delta_pressure, double delta_volume) {
        this->state.update_state(delta_temp, delta_pressure, delta_volume);
        this->iteration += 1;
    }

    bool is_stable() {
        return this->state.check_stability();
    }

    void run_simulation(int max_iterations) {
        while (this->iteration < max_iterations) {
            this->simulate_step(0.1, -0.05, 0.02);
            if (!this->is_stable()) {
                break;
            }
        }
    }
};

int main() {
    BoundaryConditions initial_state(300, 1, 10);
    ThermodynamicSimulation simulation(initial_state);
    simulation.run_simulation(100);
    return 0;
}