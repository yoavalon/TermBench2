function decay_reward(reward, decay_rate, steps) {
    return reward * Math.pow(decay_rate, steps);
}

function calculate_total_reward(initial_reward, decay_rate, max_steps) {
    let total_reward = 0;
    for (let step = 0; step < max_steps; step++) {
        total_reward += decay_reward(initial_reward, decay_rate, step);
    }
    return total_reward;
}

function main() {
    let initial_reward = 100.0;
    let decay_rate = 0.95;
    let max_steps = 1000;
    let total_reward = calculate_total_reward(initial_reward, decay_rate, max_steps);
    console.log(total_reward);
}

main();