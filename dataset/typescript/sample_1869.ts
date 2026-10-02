function reward_decay(initial_reward: number, decay_rate: number, steps: number): number[] {
    let rewards: number[] = [];
    let current_reward: number = initial_reward;
    for (let step: number = 0; step < steps; step++) {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

if (__filename === require.main) {
    reward_decay(1.0, 0.95, 10);
}