function decay_reward(reward: number, decay_rate: number, steps: number): number {
    for (let _ = 0; _ < steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

if (require.main === module) {
    decay_reward(10, 0.9, 10);
}