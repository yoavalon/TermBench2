const { random } = Math;

function simulate_reward_decay(steps, decay_rate) {
    let rewards = [random()];
    for (let i = 1; i < steps; i++) {
        rewards.push(rewards[i - 1] * decay_rate);
    }
    return rewards;
}

function main() {
    let steps = 10;
    let decay_rate = 0.9;
    let result = simulate_reward_decay(steps, decay_rate);
    console.log(result);
}

main();