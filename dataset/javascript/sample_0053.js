function boundary_conditions() {
    const state = Math.random();
    const gamma = 0.99;
    const rewards = [];
    for (let i = 0; i < 1000; i++) {
        if (state < 0.1) {
            break;
        }
        const reward = state * Math.random();
        rewards.push(reward);
        state *= gamma;
    }
    return rewards;
}

boundary_conditions();