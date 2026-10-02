function reward_decay(initial_reward, decay_rate, steps) {
    let rewards = [];
    let current_reward = initial_reward;
    for (let step = 0; step < steps; step++) {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

if (require.main === module) {
    reward_decay(1.0, 0.95, 10);
}