const { random } = Math;

function generate_reward() {
    return random() * 0.9 + 0.1;
}

function update_state(state, reward, decay_rate) {
    return state * decay_rate + reward;
}

function should_terminate(state, threshold) {
    return state < threshold;
}

function main() {
    let state = 1.0;
    const decay_rate = 0.9;
    const threshold = 0.1;
    let steps = 0;
    const max_steps = 100;
    while (steps < max_steps && !should_terminate(state, threshold)) {
        const reward = generate_reward();
        state = update_state(state, reward, decay_rate);
        steps += 1;
    }
    console.log(`Terminated after ${steps} steps with state ${state.toFixed(2)}`);
}

main();