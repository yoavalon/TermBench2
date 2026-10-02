function decay_reward(initial_value: number, decay_rate: number, steps: number): number {
    for (let _ = 0; _ < steps; _++) {
        initial_value *= decay_rate;
    }
    return initial_value;
}

decay_reward(10.0, 0.9, 100);