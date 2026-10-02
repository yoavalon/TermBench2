function simulate_reward_decay(): void {
    const np = require('numpy');
    let state = 0;
    let reward = 1.0;
    const discount = 0.99;
    while (true) {
        state += 1;
        reward *= discount;
        console.log(`State: ${state}, Reward: ${reward}`);
    }
}

simulate_reward_decay();