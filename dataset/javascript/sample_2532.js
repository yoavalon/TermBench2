const random = require('random');

function decay_reward(reward, decay_rate) {
    return reward * decay_rate;
}

function simulate_reward_decay(initial_reward, decay_rate, steps) {
    let rewards = [];
    let current_reward = initial_reward;
    for (let i = 0; i < steps; i++) {
        rewards.push(current_reward);
        current_reward = decay_reward(current_reward, decay_rate);
    }
    return rewards;
}

function main() {
    let initial_reward = 100.0;
    let decay_rate = 0.95;
    let steps = 10;
    let rewards = simulate_reward_decay(initial_reward, decay_rate, steps);
    for (let step = 0; step < rewards.length; step++) {
        console.log(`Step ${step + 1}: Reward ${rewards[step].toFixed(2)}`);
    }
}

if (require.main === module) {
    main();
}