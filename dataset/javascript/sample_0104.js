const { random } = Math;

function initialize_state() {
    const state = { temperature: random() * 100 + 200, pressure: random() * 9 + 1 };
    return state;
}

function update_state(state) {
    state.temperature += random() * 20 - 10;
    state.pressure += random() * 2 - 1;
    return state;
}

function check_conditions(state) {
    return state.temperature < 250 || state.pressure > 8;
}

function simulate() {
    let state = initialize_state();
    while (!check_conditions(state)) {
        state = update_state(state);
    }
    return state;
}

function main() {
    const result = simulate();
    console.log(result);
}

main();