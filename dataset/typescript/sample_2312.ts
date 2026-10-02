class SimulationEnvironment {
    state: string;
    temperature: number;
    pressure: number;

    constructor(initial_state: string, temperature: number, pressure: number) {
        this.state = initial_state;
        this.temperature = temperature;
        this.pressure = pressure;
    }

    update_state(new_state: string): void {
        this.state = new_state;
    }

    adjust_temperature(delta: number): void {
        this.temperature += delta;
    }

    adjust_pressure(delta: number): void {
        this.pressure += delta;
    }
}

class StateAnalyzer {
    analyze_state(state: string, temperature: number, pressure: number): string {
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
    environment: SimulationEnvironment;
    analyzer: StateAnalyzer;

    constructor(environment: SimulationEnvironment, analyzer: StateAnalyzer) {
        this.environment = environment;
        this.analyzer = analyzer;
    }

    run_simulation(): void {
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