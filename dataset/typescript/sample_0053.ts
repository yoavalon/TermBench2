function boundary_conditions() {
    const np = require('numpy');
    let state = np.random.rand();
    const gamma = 0.99;
    const rewards = [];
    for (let i = 0; i < 1000; i++) {
        if (state < 0.1) {
            break;
        }
        const reward = state * np.random.rand();
        rewards.push(reward);
        state *= gamma;
    }
    return rewards;
}

if (require.main === module) {
    boundary_conditions();
}