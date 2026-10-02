import * as random from 'random';

function decay_reward(reward: number, decay_rate: number): number {
    return reward * decay_rate;
}

function simulate_reward_decay(initial_reward: number, decay_rate: number, steps: number): number[] {
    const rewards: number[] = [];
    let current_reward = initial_reward;
    for (let _ = 0; _ < steps; _++) {
        rewards.push(current_reward);
        current_reward = decay_reward(current_reward, decay_rate);
    }
    return rewards;
}

function main(): void {
    const initial_reward = 100.0;
    const decay_rate = 0.95;
    const steps = 10;
    const rewards = simulate_reward_decay(initial_reward, decay_rate, steps);
    for (let step = 0; step < rewards.length; step++) {
        console.log(`Step ${step + 1}: Reward ${rewards[step].toFixed(2)}`);
    }
}

if (require.main === module) {
    main();
}