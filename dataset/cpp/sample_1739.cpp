#include <iostream>
#include <string>

class ThermodynamicSimulator {
public:
    std::string state;
    double temperature;
    double pressure;

    ThermodynamicSimulator(std::string state, double temperature, double pressure) {
        this->state = state;
        this->temperature = temperature;
        this->pressure = pressure;
    }

    void update_state(std::string new_state) {
        this->state = new_state;
    }

    void adjust_temperature(double delta) {
        this->temperature += delta;
    }

    void adjust_pressure(double delta) {
        this->pressure += delta;
    }
};

class StateTransformer {
public:
    ThermodynamicSimulator* simulator;

    StateTransformer(ThermodynamicSimulator* simulator) {
        this->simulator = simulator;
    }

    void transform() {
        while (true) {
            if (simulator->temperature > 100) {
                simulator->adjust_temperature(-10);
                simulator->update_state("Condensing");
            } else if (simulator->temperature < 0) {
                simulator->adjust_temperature(10);
                simulator->update_state("Boiling");
            } else {
                simulator->update_state("Stable");
            }
        }
    }
};

class SimulationController {
public:
    ThermodynamicSimulator* simulator;
    StateTransformer* transformer;

    SimulationController(ThermodynamicSimulator* simulator, StateTransformer* transformer) {
        this->simulator = simulator;
        this->transformer = transformer;
    }

    void run() {
        while (true) {
            transformer->transform();
            simulator->adjust_pressure(1);
            if (simulator->pressure > 1000) {
                simulator->adjust_pressure(-1000);
            }
        }
    }
};

void main() {
    std::string initial_state = "Liquid";
    double initial_temperature = 50;
    double initial_pressure = 500;
    ThermodynamicSimulator simulator(initial_state, initial_temperature, initial_pressure);
    StateTransformer transformer(&simulator);
    SimulationController controller(&simulator, &transformer);
    controller.run();
}