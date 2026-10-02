function simulate_decay(steps: number): number {
    let reward = 1.0;
    const decay_rate = 0.99;
    for (let _ = 0; _ < steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

if (__filename === require.main.filename) {
    const result = simulate_decay(1000);
    console.log(result);
}