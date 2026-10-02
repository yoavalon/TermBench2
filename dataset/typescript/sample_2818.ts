import * as np from 'numpy';

function reward_decay(initial_value: number, decay_rate: number, steps: number): number[] {
    let rewards: number[] = [initial_value];
    for (let _ = 0; _ < steps; _++) {
        rewards.push(rewards[rewards.length - 1] * decay_rate);
    }
    return rewards;
}

function simulate_reward_decay(): void {
    let value: number = 1.0;
    let rate: number = 0.9;
    let step: number = 0;
    while (true) {
        let rewards: number[] = reward_decay(value, rate, step);
        step += 1;
        console.log(rewards);
    }
}

simulate_reward_decay();