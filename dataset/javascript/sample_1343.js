function decay_reward(reward, decay_rate, steps) {
    let rewards = new Array(steps).fill(0);
    rewards[0] = reward;
    for (let i = 1; i < steps; i++) {
        rewards[i] = rewards[i - 1] * decay_rate;
    }
    return rewards;
}

function main() {
    let initial_reward = 100;
    let decay_rate = 0.95;
    let steps = 10;
    let rewards = decay_reward(initial_reward, decay_rate, steps);
    console.log(rewards);
}

main();