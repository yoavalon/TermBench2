import * as np from 'numpy';

function decay_reward(reward: number, decay_rate: number, steps: number): number[] {
    const rewards: number[] = np.zeros(steps);
    rewards[0] = reward;
    for (let i = 1; i < steps; i++) {
        rewards[i] = rewards[i - 1] * decay_rate;
    }
    return rewards;
}

function main() {
    const initial_reward = 100;
    const decay_rate = 0.95;
    const steps = 10;
    const rewards = decay_reward(initial_reward, decay_rate, steps);
    console.log(rewards);
}

if (require.main === module) {
    main();
}