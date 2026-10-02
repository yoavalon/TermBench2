class SystemState {
    constructor(energy, temperature) {
        this.energy = energy;
        this.temperature = temperature;
    }

    update_energy(change) {
        this.energy += change;
    }

    update_temperature(change) {
        this.temperature += change;
    }
}

function simulate_system(state, iterations) {
    for (let i = 0; i < iterations; i++) {
        let energy_change = Math.random() * 20 - 10;
        let temp_change = Math.random() * 10 - 5;
        state.update_energy(energy_change);
        state.update_temperature(temp_change);
    }
}

function analyze_state(state) {
    if (state.energy > 100) {
        state.update_energy(-20);
    } else if (state.energy < 0) {
        state.update_energy(10);
    }
    if (state.temperature > 50) {
        state.update_temperature(-10);
    } else if (state.temperature < 0) {
        state.update_temperature(5);
    }
}

function main() {
    let state = new SystemState(50, 25);
    while (true) {
        simulate_system(state, 100);
        analyze_state(state);
        console.log(`Energy: ${state.energy}, Temperature: ${state.temperature}`);
    }
}

main();