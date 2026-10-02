function update_state(state, params) {
    for (let key in params) {
        state[key] += params[key];
    }
    return state;
}

function check_stability(state, thresholds) {
    for (let key in thresholds) {
        if (Math.abs(state[key]) > thresholds[key]) {
            return false;
        }
    }
    return true;
}

function simulate(state, params, thresholds, steps) {
    for (let _ = 0; _ < steps; _++) {
        state = update_state(state, params);
        if (!check_stability(state, thresholds)) {
            return state;
        }
    }
    return state;
}

function main() {
    let state = {'temp': 0, 'pressure': 0};
    let params = {'temp': 0.1, 'pressure': -0.05};
    let thresholds = {'temp': 1, 'pressure': 0.5};
    let steps = 100;
    let final_state = simulate(state, params, thresholds, steps);
    console.log(final_state);
}

main();