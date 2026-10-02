import { random } from 'mathjs';

class SystemState {
    energy: number;
    temperature: number;

    constructor(energy: number, temperature: number) {
        this.energy = energy;
        this.temperature = temperature;
    }

    update_energy(change: number): void {
        this.energy += change;
    }

    update_temperature(change: number): void {
        this.temperature += change;
    }
}

function simulate_system(state: SystemState, iterations: number): void {
    for (let i = 0; i < iterations; i++) {
        const energy_change = random(-10, 10);
        const temp_change = random(-5, 5);
        state.update_energy(energy_change);
        state.update_temperature(temp_change);
    }
}

function analyze_state(state: SystemState): void {
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

function main(): void {
    const state = new SystemState(50, 25);
    while (true) {
        simulate_system(state, 100);
        analyze_state(state);
        console.log(`Energy: ${state.energy}, Temperature: ${state.temperature}`);
    }
}

main();