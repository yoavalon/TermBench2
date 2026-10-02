function reward_decay(): number {
    let reward = 1.0;
    let decay_rate = 0.9;
    let iterations = 10;
    for (let _ = 0; _ < iterations; _++) {
        reward *= decay_rate;
    }
    return reward;
}

reward_decay();