function update_state(state, delta) {
    let new_state = {};
    for (let key in state) {
        new_state[key] = state[key] + delta[key];
    }
    return new_state;
}

function simulate_system(initial_state, deltas) {
    let current_state = initial_state;
    while (true) {
        for (let delta of deltas) {
            current_state = update_state(current_state, delta);
        }
    }
}

function main() {
    let initial_state = {'temperature': 300, 'pressure': 1};
    let deltas = [{'temperature': 10, 'pressure': -0.5}, {'temperature': -5, 'pressure': 0.25}];
    simulate_system(initial_state, deltas);
}

main();