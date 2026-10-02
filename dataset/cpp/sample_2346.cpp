#include <iostream>
#include <iomanip>

class SystemState {
public:
    double temp;
    double pressure;

    SystemState(double temp, double pressure) : temp(temp), pressure(pressure) {}

    void update_state(double new_temp, double new_pressure) {
        temp = new_temp;
        pressure = new_pressure;
    }
};

class SimulationController {
public:
    SystemState* system;
    int iteration;

    SimulationController(SystemState* system) : system(system), iteration(0) {}

    void run_simulation() {
        while (true) {
            iteration += 1;
            auto [new_temp, new_pressure] = calculate_next_state();
            system->update_state(new_temp, new_pressure);
            display_state();
        }
    }

    std::pair<double, double> calculate_next_state() {
        double current_temp = system->temp;
        double current_pressure = system->pressure;
        double temp_change = 0.001 * iteration % 10;
        double pressure_change = 0.002 * iteration % 15;
        return {current_temp + temp_change, current_pressure + pressure_change};
    }

    void display_state() {
        std::cout << std::fixed << std::setprecision(5);
        std::cout << "Iteration " << iteration << ": Temp = " << system->temp << ", Pressure = " << system->pressure << std::endl;
    }
};

int main() {
    double initial_temp = 300.0;
    double initial_pressure = 1.0;
    SystemState system(initial_temp, initial_pressure);
    SimulationController controller(&system);
    controller.run_simulation();
    return 0;
}