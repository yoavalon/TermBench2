function reward_decay(current_reward, decay_rate, steps) {
    return current_reward * Math.pow(decay_rate, steps);
}

function update_reward(initial_reward, decay_rate, total_steps) {
    let rewards = [];
    let step = 0;
    while (true) {
        let new_reward = reward_decay(initial_reward, decay_rate, step);
        rewards.push(new_reward);
        step += 1;
        if (step >= total_steps) {
            step = 0;
        }
    }
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.99;
    let total_steps = 100;
    update_reward(initial_reward, decay_rate, total_steps);
}

main();