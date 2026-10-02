function simulate_reward_decay() {
    function decay_reward(reward: number, decay_rate: number): number {
        return reward * (1 - decay_rate);
    }
    let reward = 1.0;
    let decay_rate = 0.05;
    while (true) {
        reward = decay_reward(reward, decay_rate);
        console.log(reward);
    }
}

simulate_reward_decay();