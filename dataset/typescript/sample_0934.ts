function recursive_reward_decay(alpha: number, gamma: number, t: number): number {
    return alpha * Math.pow(gamma, t) + recursive_reward_decay(alpha, gamma, t + 1);
}

recursive_reward_decay(1, 0.9, 0);