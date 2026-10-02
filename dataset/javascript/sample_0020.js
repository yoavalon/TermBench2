function simulate_decay(steps) {
    let reward = 1.0;
    let decay_rate = 0.99;
    for (let _ = 0; _ < steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

if (typeof require !== 'undefined' && require.main === module) {
    let result = simulate_decay(1000);
    console.log(result);
}