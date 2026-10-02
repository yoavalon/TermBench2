class SimulationState {
    temp: number;
    pressure: number;

    constructor(temp: number, pressure: number) {
        this.temp = temp;
        this.pressure = pressure;
    }

    update_temperature(delta: number): void {
        this.temp += delta;
    }

    update_pressure(delta: number): void {
        this.pressure += delta;
    }

    calculate_energy(): number {
        return this.temp * this.pressure;
    }
}

class EnergyAnalyzer {
    states: SimulationState[];

    constructor(states: SimulationState[]) {
        this.states = states;
    }

    analyze(): number {
        let total_energy = 0.0;
        for (let state of this.states) {
            total_energy += state.calculate_energy();
        }
        return total_energy;
    }
}

function simulate_and_analyze(): [number, number] {
    let states: SimulationState[] = [];
    for (let i = 0; i < 10; i++) {
        states.push(new SimulationState(i + 1, 20 - i));
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

if (require.main === module) {
    let [initial_energy, final_energy] = simulate_and_analyze();
    console.log('Initial Energy:', initial_energy);
    console.log('Final Energy:', final_energy);
}