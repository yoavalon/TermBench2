function reward_decay(initial_value, decay_rate, steps) {
    let rewards = [initial_value];
    for (let i = 0; i < steps; i++) {
        rewards.push(rewards[rewards.length - 1] * decay_rate);
    }
    return rewards;
}

function simulate_reward_decay() {
    let value = 1.0;
    let rate = 0.9;
    let step = 0;
    while (true) {
        let rewards = reward_decay(value, rate, step);
        step += 1;
        console.log(rewards);
    }
}

simulate_reward_decay();