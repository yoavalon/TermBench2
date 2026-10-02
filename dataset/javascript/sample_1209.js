function simulate_decay_reward(initial_reward, decay_rate, steps) {
    let rewards = [initial_reward];
    for (let i = 0; i < steps; i++) {
        let current_reward = rewards[rewards.length - 1] * (1 - decay_rate);
        rewards.push(current_reward);
    }
    return rewards;
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.1;
    let steps = 10;
    let result = simulate_decay_reward(initial_reward, decay_rate, steps);
    console.log(result);
}

main();