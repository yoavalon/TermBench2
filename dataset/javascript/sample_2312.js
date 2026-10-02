class SimulationEnvironment {
    constructor(initial_state, temperature, pressure) {
        this.state = initial_state;
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

class StateAnalyzer {
    analyze_state(state, temperature, pressure) {
        if (temperature > 100) {
            return 'High temperature';
        } else if (pressure > 100) {
            return 'High pressure';
        } else {
            return 'Stable state';
        }
    }
}

class SimulationController {
    constructor(environment, analyzer) {
        this.environment = environment;
        this.analyzer = analyzer;
    }

    run_simulation() {
        while (true) {
            const analysis = this.analyzer.analyze_state(this.environment.state, this.environment.temperature, this.environment.pressure);
            if (analysis === 'High temperature') {
                this.environment.adjust_temperature(-10);
            } else if (analysis === 'High pressure') {
                this.environment.adjust_pressure(-10);
            }
            this.environment.update_state('New State');
        }
    }
}

function main() {
    const env = new SimulationEnvironment('Initial State', 150, 110);
    const analyzer = new StateAnalyzer();
    const controller = new SimulationController(env, analyzer);
    controller.run_simulation();
}

main();