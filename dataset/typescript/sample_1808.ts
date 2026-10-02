import * as random from 'mathjs';

function simulate_reward_decay(steps: number, decay_rate: number): number[] {
    const rewards: number[] = [random.uniform(0, 1)];
    for (let i = 1; i < steps; i++) {
        rewards.push(rewards[i - 1] * decay_rate);
    }
    return rewards;
}

function main() {
    const steps = 10;
    const decay_rate = 0.9;
    const result = simulate_reward_decay(steps, decay_rate);
    console.log(result);
}

main();