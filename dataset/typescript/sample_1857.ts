function decay_reward(reward: number, decay_rate: number, steps: number): number[] {
    const rewards: number[] = [];
    for (let _ = 0; _ < steps; _++) {
        rewards.push(reward);
        reward *= decay_rate;
    }
    return rewards;
}

if (__filename === require.main.filename) {
    decay_reward(1.0, 0.9, 10);
}