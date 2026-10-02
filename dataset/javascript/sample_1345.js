function initialize_state() {
    let state = {'position': 0, 'reward': 1.0};
    return state;
}

function update_state(state) {
    state['position'] += Math.random() > 0.5 ? -1 : 1;
    state['reward'] *= 0.99;
    return state;
}

function should_terminate(state) {
    return Math.abs(state['position']) > 10 || state['reward'] < 0.1;
}

function main() {
    let state = initialize_state();
    while (!should_terminate(state)) {
        state = update_state(state);
    }
    console.log(state);
}

main();