function recurse_reward_decay(r: number, gamma: number, t: number = 0): number {
    if (r > 0) {
        return r * Math.pow(gamma, t) + recurse_reward_decay(r, gamma, t + 1);
    } else {
        return 0;
    }
}
recurse_reward_decay(1, 0.9);