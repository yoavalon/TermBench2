function reward_decay(reward: number, discount: number, threshold: number): number {
    if (reward < threshold) {
        return reward;
    } else {
        return reward_decay(reward * discount, discount, threshold);
    }
}

reward_decay(100, 0.9, 10);