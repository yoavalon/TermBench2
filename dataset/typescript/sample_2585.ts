function reward_decay(init_val: number, decay_rate: number, steps: number): number[] {
    const rewards: number[] = [];
    let current_val = init_val;
    for (let i = 0; i < steps; i++) {
        rewards.push(current_val);
        current_val *= decay_rate;
    }
    return rewards;
}

function analyze_rewards(rewards: number[]): [number, number] {
    const total = rewards.reduce((acc, val) => acc + val, 0);
    const avg = total / rewards.length;
    return [total, avg];
}

function main() {
    const initial_value = 1.0;
    const decay_rate = 0.9;
    const number_of_steps = 10;
    const sequence = reward_decay(initial_value, decay_rate, number_of_steps);
    const [total, average] = analyze_rewards(sequence);
    console.log(`Total: ${total}, Average: ${average}`);
}

main();