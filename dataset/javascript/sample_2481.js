function calculate_discounted_rewards(rewards, decay_rate, steps) {
    let discounted_rewards = [];
    for (let i = 0; i < steps; i++) {
        discounted_rewards.push(rewards[i] * Math.pow(decay_rate, i));
    }
    return discounted_rewards;
}

function main() {
    let rewards = [100, 90, 80, 70, 60];
    let decay_rate = 0.9;
    let steps = 5;
    let result = calculate_discounted_rewards(rewards, decay_rate, steps);
    console.log(result);
}

main();