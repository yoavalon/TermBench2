const math = require('mathjs');

class ThermodynamicState {
    constructor(temp, pressure) {
        this.temp = temp;
        this.pressure = pressure;
    }

    update_state(temp_change, pressure_change) {
        this.temp += temp_change;
        this.pressure += pressure_change;
    }

    calculate_entropy() {
        if (this.temp <= 0) {
            return NaN;
        }
        return this.pressure / this.temp;
    }
}

class SimulationController {
    constructor(initial_state, iterations) {
        this.state = initial_state;
        this.iterations = iterations;
        this.data = [];
    }

    run_simulation() {
        for (let _ = 0; _ < this.iterations; _++) {
            this.state.update_state(0.1, -0.05);
            this.data.push(this.state.calculate_entropy());
        }
    }

    get_results() {
        return this.data;
    }
}

function analyze_data(data) {
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

function main() {
    const initial_state = new ThermodynamicState(300, 100);
    const controller = new SimulationController(initial_state, 50);
    controller.run_simulation();
    const results = controller.get_results();
    const average_entropy = analyze_data(results);
    console.log(`Average Entropy: ${average_entropy}`);
}

main();