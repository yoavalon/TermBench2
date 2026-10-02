function reward_decay(epochs: number, decay_rate: number): number[] {
    let rewards: number[] = [];
    let current_reward: number = 1.0;
    for (let i = 0; i < epochs; i++) {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

if (__filename === require.main.filename) {
    console.log(reward_decay(10, 0.9));
}