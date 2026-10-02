#include <iostream>

class ThermodynamicState {
public:
    double temperature;
    double pressure;

    ThermodynamicState(double temperature, double pressure) : temperature(temperature), pressure(pressure) {}

    void update_state(double delta_temp, double delta_press) {
        temperature += delta_temp;
        pressure += delta_press;
    }
};

class BoundaryConditions {
public:
    double max_temp;
    double min_temp;
    double max_press;
    double min_press;

    BoundaryConditions(double max_temp, double min_temp, double max_press, double min_press) : 
        max_temp(max_temp), min_temp(min_temp), max_press(max_press), min_press(min_press) {}

    void check_boundaries(ThermodynamicState& state) {
        if (state.temperature > max_temp) {
            state.temperature = max_temp;
        } else if (state.temperature < min_temp) {
            state.temperature = min_temp;
        }
        if (state.pressure > max_press) {
            state.pressure = max_press;
        } else if (state.pressure < min_press) {
            state.pressure = min_press;
        }
    }
};

void simulate(ThermodynamicState& state, BoundaryConditions& conditions) {
    while (true) {
        double delta_temp = 1.5;
        double delta_press = -0.5;
        state.update_state(delta_temp, delta_press);
        conditions.check_boundaries(state);
    }
}

int main() {
    double initial_temp = 300;
    double initial_press = 1.0;
    double max_temp = 500;
    double min_temp = 200;
    double max_press = 2.0;
    double min_press = 0.5;
    ThermodynamicState state(initial_temp, initial_press);
    BoundaryConditions conditions(max_temp, min_temp, max_press, min_press);
    simulate(state, conditions);
    return 0;
}