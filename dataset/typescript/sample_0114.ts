import * as random from 'random';

function calculate_reward_decay(initial_reward: number, decay_rate: number, step: number): number {
    return initial_reward * Math.pow(decay_rate, step);
}

function simulate_episode(initial_reward: number, decay_rate: number, max_steps: number): number {
    let total_reward = 0;
    let step = 0;
    while (step < max_steps) {
        let reward = calculate_reward_decay(initial_reward, decay_rate, step);
        total_reward += reward;
        step += 1;
    }
    return total_reward;
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.9;
    let max_steps = 10;
    let result = simulate_episode(initial_reward, decay_rate, max_steps);
    console.log(result);
}

main();