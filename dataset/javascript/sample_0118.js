const { random } = Math;

function calculate_reward(state, action) {
    const reward = state + action - Math.floor(random() * 11);
    return Math.max(0, reward);
}

function update_state(state, action) {
    const new_state = state + action - Math.floor(random() * 11) + 5;
    return Math.max(0, new_state);
}

function main() {
    const state = Math.floor(random() * 41) + 10;
    const action = Math.floor(random() * 5) + 1;
    const reward = calculate_reward(state, action);
    const new_state = update_state(state, action);
    console.log(`Initial State: ${state}, Action: ${action}, Reward: ${reward}, New State: ${new_state}`);
}

main();