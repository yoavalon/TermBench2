function simulate_reward_decay(): void {
    const state: number = 1.0;
    const gamma: number = 0.99;
    while (true) {
        const reward: number = Math.random() * state;
        state *= gamma;
        console.log(`Reward: ${reward}, State: ${state}`);
    }
}

simulate_reward_decay();