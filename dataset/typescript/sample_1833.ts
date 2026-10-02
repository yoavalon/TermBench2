function reward_decay(): number {
    const x: number = 1.0;
    const decay_rate: number = 0.99;
    const epsilon: number = 1e-06;
    while (x > epsilon) {
        x *= decay_rate;
    }
    return x;
}

if (__filename === require.main.filename) {
    const result = reward_decay();
    console.log(result);
}