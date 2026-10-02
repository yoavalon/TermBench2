function update_state(state, params) {
    state.temperature += params.heat;
    state.pressure += params.pressure_change;
    return state;
}

function simulate_thermodynamics(initial_state, params, steps) {
    for (let i = 0; i < steps; i++) {
        initial_state = update_state(initial_state, params);
    }
    return initial_state;
}

function main() {
    const state = { temperature: 300, pressure: 1 };
    const params = { heat: 10, pressure_change: 2 };
    const steps = 5;
    const final_state = simulate_thermodynamics(state, params, steps);
    console.log(final_state);
}

main();