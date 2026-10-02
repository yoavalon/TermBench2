function simulate_decay_reward(initial_reward: number, decay_rate: number, steps: number): number[] {
    let rewards: number[] = [initial_reward];
    for (let _ = 0; _ < steps; _++) {
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