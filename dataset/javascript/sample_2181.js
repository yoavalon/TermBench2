function simulate_reward_decay() {
    const state = 1.0;
    const gamma = 0.99;
    while (true) {
        const reward = Math.random() * state;
        state *= gamma;
        console.log(`Reward: ${reward}, State: ${state}`);
    }
}
simulate_reward_decay();