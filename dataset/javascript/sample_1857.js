function decay_reward(reward, decay_rate, steps) {
    let rewards = [];
    for (let i = 0; i < steps; i++) {
        rewards.push(reward);
        reward *= decay_rate;
    }
    return rewards;
}

decay_reward(1.0, 0.9, 10);