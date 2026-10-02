function update_state(state, rule) {
    let new_state = [];
    for (let i = 0; i < state.length; i++) {
        let left = i > 0 ? state[i - 1] : state[state.length - 1];
        let right = state[(i + 1) % state.length];
        new_state.push(rule(left, state[i], right));
    }
    return new_state;
}

function cellular_automaton(steps, initial, rule) {
    let state = initial;
    for (let _ = 0; _ < steps; _++) {
        state = update_state(state, rule);
    }
    return state;
}

function rule_conway(left, center, right) {
    let count = left + center + right;
    return count === 3 ? 1 : count === 2 ? 0 : center;
}

function main() {
    let initial_state = [0, 1, 0, 1, 0, 1, 0, 1, 0, 1];
    let steps = 5;
    let final_state = cellular_automaton(steps, initial_state, rule_conway);
    console.log(final_state);
}

main();