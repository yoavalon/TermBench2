function compute_temperature_change(initial_temp: number, final_temp: number, rate: number): number {
    let change = (final_temp - initial_temp) * rate;
    return change;
}

function update_state(state: { temperature: number, energy: number }, change: number): { temperature: number, energy: number } {
    state.temperature += change;
    state.energy += change * 1000;
    return state;
}

function simulate_state(initial_temp: number, final_temp: number, rate: number, steps: number): { temperature: number, energy: number } {
    let state = { temperature: initial_temp, energy: 0 };
    for (let i = 0; i < steps; i++) {
        let change = compute_temperature_change(state.temperature, final_temp, rate);
        state = update_state(state, change);
    }
    return state;
}

function main() {
    let initial_temp = 20;
    let final_temp = 100;
    let rate = 0.1;
    let steps = 10;
    let result = simulate_state(initial_temp, final_temp, rate, steps);
    console.log(result);
}

main();