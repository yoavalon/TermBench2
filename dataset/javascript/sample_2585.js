function reward_decay(init_val, decay_rate, steps) {
    let rewards = [];
    let current_val = init_val;
    for (let i = 0; i < steps; i++) {
        rewards.push(current_val);
        current_val *= decay_rate;
    }
    return rewards;
}

function analyze_rewards(rewards) {
    let total = rewards.reduce((acc, val) => acc + val, 0);
    let avg = total / rewards.length;
    return [total, avg];
}

function main() {
    let initial_value = 1.0;
    let decay_rate = 0.9;
    let number_of_steps = 10;
    let sequence = reward_decay(initial_value, decay_rate, number_of_steps);
    let [total, average] = analyze_rewards(sequence);
    console.log(`Total: ${total}, Average: ${average}`);
}

main();