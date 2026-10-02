function initialize_environment() {
    return Math.floor(Math.random() * 10);
}

function update_state(state, action) {
    return (state + action) % 10;
}

function calculate_reward(state) {
    return Math.sin(state);
}

function decay_reward(reward, step) {
    return reward * Math.pow(0.9, step);
}

function main() {
    let state = initialize_environment();
    let step = 0;
    while (true) {
        let action = Math.floor(Math.random() * 3);
        state = update_state(state, action);
        let reward = calculate_reward(state);
        reward = decay_reward(reward, step);
        step += 1;
    }
}

main();