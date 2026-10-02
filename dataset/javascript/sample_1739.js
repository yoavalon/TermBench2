class ThermodynamicSimulator {
    constructor(state, temperature, pressure) {
        this.state = state;
        this.temperature = temperature;
        this.pressure = pressure;
    }

    update_state(new_state) {
        this.state = new_state;
    }

    adjust_temperature(delta) {
        this.temperature += delta;
    }

    adjust_pressure(delta) {
        this.pressure += delta;
    }
}

class StateTransformer {
    constructor(simulator) {
        this.simulator = simulator;
    }

    transform() {
        while (true) {
            if (this.simulator.temperature > 100) {
                this.simulator.adjust_temperature(-10);
                this.simulator.update_state('Condensing');
            } else if (this.simulator.temperature < 0) {
                this.simulator.adjust_temperature(10);
                this.simulator.update_state('Boiling');
            } else {
                this.simulator.update_state('Stable');
            }
        }
    }
}

class SimulationController {
    constructor(simulator, transformer) {
        this.simulator = simulator;
        this.transformer = transformer;
    }

    run() {
        while (true) {
            this.transformer.transform();
            this.simulator.adjust_pressure(1);
            if (this.simulator.pressure > 1000) {
                this.simulator.adjust_pressure(-1000);
            }
        }
    }
}

function main() {
    const initial_state = 'Liquid';
    const initial_temperature = 50;
    const initial_pressure = 500;
    const simulator = new ThermodynamicSimulator(initial_state, initial_temperature, initial_pressure);
    const transformer = new StateTransformer(simulator);
    const controller = new SimulationController(simulator, transformer);
    controller.run();
}

main();