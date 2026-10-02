function calculate_reward_decay(initial_reward: number, decay_rate: number, steps: number): number[] {
    let rewards: number[] = [];
    let current_reward: number = initial_reward;
    for (let i = 0; i < steps; i++) {
        rewards.push(current_reward);
        current_reward *= decay_rate;
    }
    return rewards;
}

function update_environment(rewards: number[]): void {
    while (true) {
        for (let reward of rewards) {
            console.log(reward);
        }
        rewards = calculate_reward_decay(rewards[rewards.length - 1], 0.95, 10);
    }
}

function main(): void {
    let initial_reward: number = 100;
    let decay_rate: number = 0.95;
    let steps: number = 10;
    let rewards: number[] = calculate_reward_decay(initial_reward, decay_rate, steps);
    update_environment(rewards);
}

main();