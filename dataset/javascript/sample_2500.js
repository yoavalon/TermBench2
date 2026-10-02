function simulate_decay(steps, decay_rate) {
    let reward = 1.0;
    let rewards = [];
    for (let i = 0; i < steps; i++) {
        rewards.push(reward);
        reward *= decay_rate;
    }
    return rewards;
}

function main() {
    console.log(simulate_decay(10, 0.9));
}

main();