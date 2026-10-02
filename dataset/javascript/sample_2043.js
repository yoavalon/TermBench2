class SimulationState {
    constructor(temp, pressure) {
        this.temp = temp;
        this.pressure = pressure;
    }

    update_temperature(delta) {
        this.temp += delta;
    }

    update_pressure(delta) {
        this.pressure += delta;
    }

    calculate_energy() {
        return this.temp * this.pressure;
    }
}

class EnergyAnalyzer {
    constructor(states) {
        this.states = states;
    }

    analyze() {
        let total_energy = 0.0;
        for (let state of this.states) {
            total_energy += state.calculate_energy();
        }
        return total_energy;
    }
}

function simulate_and_analyze() {
    let states = [];
    for (let i = 0; i < 10; i++) {
        states.push(new SimulationState(parseFloat(i + 1), parseFloat(20 - i)));
    }
    let analyzer = new EnergyAnalyzer(states);
    let energy = analyzer.analyze();
    for (let state of states) {
        state.update_temperature(0.5);
        state.update_pressure(-0.5);
    }
    let final_energy = analyzer.analyze();
    return [energy, final_energy];
}

if (typeof require !== 'undefined' && require.main === module) {
    let [initial_energy, final_energy] = simulate_and_analyze();
    console.log('Initial Energy:', initial_energy);
    console.log('Final Energy:', final_energy);
}