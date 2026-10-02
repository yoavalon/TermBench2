import * as math from 'mathjs';

class ThermodynamicState {
    temp: number;
    pressure: number;

    constructor(temp: number, pressure: number) {
        this.temp = temp;
        this.pressure = pressure;
    }

    update_state(temp_change: number, pressure_change: number): void {
        this.temp += temp_change;
        this.pressure += pressure_change;
    }

    calculate_entropy(): number {
        if (this.temp <= 0) {
            return NaN;
        }
        return this.pressure / this.temp;
    }
}

class SimulationController {
    state: ThermodynamicState;
    iterations: number;
    data: number[];

    constructor(initial_state: ThermodynamicState, iterations: number) {
        this.state = initial_state;
        this.iterations = iterations;
        this.data = [];
    }

    run_simulation(): void {
        for (let _ = 0; _ < this.iterations; _++) {
            this.state.update_state(0.1, -0.05);
            this.data.push(this.state.calculate_entropy());
        }
    }

    get_results(): number[] {
        return this.data;
    }
}

function analyze_data(data: number[]): number {
    let total = 0;
    let count = 0;
    for (let value of data) {
        if (!isNaN(value)) {
            total += value;
            count += 1;
        }
    }
    return count > 0 ? total / count : NaN;
}

function main(): void {
    let initial_state = new ThermodynamicState(300, 100);
    let controller = new SimulationController(initial_state, 50);
    controller.run_simulation();
    let results = controller.get_results();
    let average_entropy = analyze_data(results);
    console.log(`Average Entropy: ${average_entropy}`);
}

main();