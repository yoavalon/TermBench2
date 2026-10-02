function decay_reward(alpha: number, gamma: number, epochs: number): number[] {
    let rewards: number[] = [];
    let reward: number = 1.0;
    for (let i: number = 0; i < epochs; i++) {
        reward *= gamma;
        rewards.push(reward);
    }
    return rewards;
}

decay_reward(0.1, 0.95, 10);