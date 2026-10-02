#include <iostream>
#include <cmath>

class Simulation {
public:
    Simulation(double state) : state(state) {}

    void update_state(double change) {
        state += change;
    }

    bool is_stable() {
        return std::abs(state) < 0.01;
    }

private:
    double state;
};

class BoundaryConditions {
public:
    BoundaryConditions(double min_val, double max_val) : min_val(min_val), max_val(max_val) {}

    double enforce_boundaries(double state) {
        if (state < min_val) {
            return min_val;
        } else if (state > max_val) {
            return max_val;
        }
        return state;
    }

private:
    double min_val, max_val;
};

class Controller {
public:
    Controller(Simulation simulation, BoundaryConditions boundary_conditions) 
        : simulation(simulation), boundary_conditions(boundary_conditions) {}

    void run() {
        double change = 0.1;
        while (true) {
            simulation.update_state(change);
            simulation.state = boundary_conditions.enforce_boundaries(simulation.state);
            if (simulation.is_stable()) {
                break;
            }
        }
    }

private:
    Simulation simulation;
    BoundaryConditions boundary_conditions;
};

int main() {
    Simulation simulation(0.0);
    BoundaryConditions boundary_conditions(-1.0, 1.0);
    Controller controller(simulation, boundary_conditions);
    controller.run();
    return 0;
}