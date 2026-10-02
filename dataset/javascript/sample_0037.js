function decay_reward(alpha, gamma, epochs) {
    let rewards = [];
    let reward = 1.0;
    for (let i = 0; i < epochs; i++) {
        reward *= gamma;
        rewards.push(reward);
    }
    return rewards;
}

decay_reward(0.1, 0.95, 10);