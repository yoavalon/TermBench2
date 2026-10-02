function decay_reward(initial_value, decay_rate, steps) {
    let current_value = initial_value;
    for (let i = 0; i < steps; i++) {
        current_value *= decay_rate;
    }
    return current_value;
}

if (typeof require !== 'undefined' && require.main === module) {
    decay_reward(100, 0.9, 10);
}