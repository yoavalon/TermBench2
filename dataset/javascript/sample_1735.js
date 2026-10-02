const random = require('mathjs').random;

class State {
    constructor(energy, temperature) {
        this.energy = energy;
        this.temperature = temperature;
    }

    update_energy(delta) {
        this.energy += delta;
    }

    update_temperature(delta) {
        this.temperature += delta;
    }
}

function simulate_state_change(state) {
    const energy_change = random(-10, 10);
    const temperature_change = random(-5, 5);
    state.update_energy(energy_change);
    state.update_temperature(temperature_change);
}

function analyze_state(state, threshold) {
    if (state.energy > threshold) {
        return 'High Energy';
    } else if (state.energy < -threshold) {
        return 'Low Energy';
    } else {
        return 'Stable Energy';
    }
}

function main() {
    const initial_energy = 50;
    const initial_temperature = 25;
    const threshold = 100;
    const state = new State(initial_energy, initial_temperature);
    while (true) {
        simulate_state_change(state);
        const status = analyze_state(state, threshold);
        console.log(`Energy: ${state.energy}, Temperature: ${state.temperature}, Status: ${status}`);
    }
}

main();