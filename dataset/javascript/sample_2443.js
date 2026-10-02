function reward_decay(epochs, decay_rate) {
    let rewards = [];
    let current_reward = 1.0;
    for (let i = 0; i < epochs; i++) {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}
reward_decay(10, 0.9);