function compute_reward_decay(reward, decay_rate, steps) {
    return reward * Math.pow(decay_rate, steps);
}

function simulate_sequence(initial_reward, decay_rate, max_steps) {
    let sequence = [];
    let current_reward = initial_reward;
    for (let step = 0; step < max_steps; step++) {
        current_reward = compute_reward_decay(current_reward, decay_rate, 1);
        sequence.push(current_reward);
    }
    return sequence;
}

function main() {
    let initial_value = 100;
    let decay_factor = 0.95;
    let total_iterations = 10;
    let result = simulate_sequence(initial_value, decay_factor, total_iterations);
    console.log(result);
}

main();