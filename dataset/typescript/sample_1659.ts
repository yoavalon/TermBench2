function reward_decay(current_reward: number, decay_rate: number, steps: number): number {
    return current_reward * Math.pow(decay_rate, steps);
}

function update_reward(initial_reward: number, decay_rate: number, total_steps: number): void {
    const rewards: number[] = [];
    let step: number = 0;
    while (true) {
        const new_reward: number = reward_decay(initial_reward, decay_rate, step);
        rewards.push(new_reward);
        step += 1;
        if (step >= total_steps) {
            step = 0;
        }
    }
}

function main(): void {
    const initial_reward: number = 1.0;
    const decay_rate: number = 0.99;
    const total_steps: number = 100;
    update_reward(initial_reward, decay_rate, total_steps);
}

main();