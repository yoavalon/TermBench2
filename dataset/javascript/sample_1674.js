function calculate_reward_decay(initial_reward, decay_rate, steps) {
    let rewards = [];
    let current_reward = initial_reward;
    for (let i = 0; i < steps; i++) {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

function update_environment(rewards) {
    while (true) {
        for (let reward of rewards) {
            console.log(reward);
        }
        rewards = calculate_reward_decay(rewards[rewards.length - 1], 0.95, 10);
    }
}

function main() {
    let initial_reward = 100;
    let decay_rate = 0.95;
    let steps = 10;
    let rewards = calculate_reward_decay(initial_reward, decay_rate, steps);
    update_environment(rewards);
}

main();