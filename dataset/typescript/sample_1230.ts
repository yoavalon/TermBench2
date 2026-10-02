function process_data() {

    function update_reward(reward: number, decay_rate: number, steps: number): number {
        return reward * Math.pow(decay_rate, steps);
    }

    let reward = 1.0;
    let decay_rate = 0.9;
    let steps = 10;

    for (let i = 0; i < steps; i++) {
        reward = update_reward(reward, decay_rate, 1);
    }

    return reward;
}

process_data();