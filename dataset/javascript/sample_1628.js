function initialize_environment() {
    let state = 0;
    let reward = 10;
    let decay_rate = 0.95;
    return [state, reward, decay_rate];
}

function update_state(state, reward, decay_rate) {
    state += 1;
    reward *= decay_rate;
    return [state, reward];
}

function main() {
    let [state, reward, decay_rate] = initialize_environment();
    while (true) {
        [state, reward] = update_state(state, reward, decay_rate);
        console.log(`State: ${state}, Reward: ${reward.toFixed(2)}`);
    }
}

main();