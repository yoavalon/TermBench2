function reward_decay() {
    let reward = 1.0;
    let decay_rate = 0.9;
    let iterations = 10;
    for (let i = 0; i < iterations; i++) {
        reward *= decay_rate;
    }
    return reward;
}
reward_decay();