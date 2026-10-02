function decay_factor(time_step) {
    return Math.pow(0.99, time_step);
}

function calculate_reward(initial_reward, steps) {
    let reward = initial_reward;
    for (let t = 0; t < steps; t++) {
        reward *= decay_factor(t);
    }
    return reward;
}

function main() {
    let initial_value = 100;
    let steps = 0;
    while (true) {
        let reward = calculate_reward(initial_value, steps);
        console.log(`Step ${steps}: Reward ${reward.toFixed(4)}`);
        steps += 1;
    }
}

main();