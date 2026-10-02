function decay_reward(reward: number, factor: number, threshold: number): number {
    if (reward < threshold) {
        return 0;
    }
    return reward * factor;
}

function compute_reward(initial: number, factor: number, steps: number, threshold: number): number {
    let reward = initial;
    for (let i = 0; i < steps; i++) {
        reward = decay_reward(reward, factor, threshold);
    }
    return reward;
}

function main() {
    const initial_reward = 100;
    const decay_factor = 0.9;
    const steps = 10;
    const threshold = 10;
    const final_reward = compute_reward(initial_reward, decay_factor, steps, threshold);
    console.log(final_reward);
}

main();