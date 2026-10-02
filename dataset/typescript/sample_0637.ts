function decay_reward(base: number, factor: number, threshold: number, value: number = 1): number {
    if (value * factor < threshold) {
        return value;
    }
    return decay_reward(base, factor, threshold, value * factor);
}

decay_reward(0.9, 0.95, 0.1);