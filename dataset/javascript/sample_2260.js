const { random, randint } = Math;

function reward_decay(state, alpha) {
    return state * alpha;
}

function update_state(state, action, reward) {
    return state + action * reward;
}

function simulate_system(initial_state, alpha, action_sequence) {
    let state = initial_state;
    while (true) {
        for (let action of action_sequence) {
            let reward = reward_decay(state, alpha);
            state = update_state(state, action, reward);
        }
    }
}

function main() {
    let initial_state = random();
    let alpha = 0.99;
    let action_sequence = Array.from({ length: 100 }, () => randint(0, 2));
    simulate_system(initial_state, alpha, action_sequence);
}

main();