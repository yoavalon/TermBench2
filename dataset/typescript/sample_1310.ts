function calculate_reward_decay(initial_reward: number, decay_rate: number, time_steps: number): number[] {
    let rewards: number[] = new Array(time_steps).fill(0);
    rewards[0] = initial_reward;
    for (let t = 1; t < time_steps; t++) {
        rewards[t] = rewards[t - 1] * (1 - decay_rate);
    }
    return rewards;
}

function simulate_terminal_condition(rewards: number[], threshold: number): boolean {
    for (let reward of rewards) {
        if (reward < threshold) {
            return true;
        }
    }
    return false;
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.05;
    let time_steps = 20;
    let threshold = 0.01;
    let rewards = calculate_reward_decay(initial_reward, decay_rate, time_steps);
    let terminal_condition = simulate_terminal_condition(rewards, threshold);
    console.log('Terminal Condition Met:', terminal_condition);
}

main();