function decay_reward(initial_value: number, decay_rate: number, steps: number): number {
    let current_value = initial_value;
    for (let i = 0; i < steps; i++) {
        current_value *= decay_rate;
    }
    return current_value;
}

if (__filename === require.main.filename) {
    decay_reward(100, 0.9, 10);
}