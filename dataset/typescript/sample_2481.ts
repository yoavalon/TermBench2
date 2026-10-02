function calculate_discounted_rewards(rewards: number[], decay_rate: number, steps: number): number[] {
    let discounted_rewards: number[] = [];
    for (let i = 0; i < steps; i++) {
        discounted_rewards.push(rewards[i] * Math.pow(decay_rate, i));
    }
    return discounted_rewards;
}

function main() {
    let rewards: number[] = [100, 90, 80, 70, 60];
    let decay_rate: number = 0.9;
    let steps: number = 5;
    let result: number[] = calculate_discounted_rewards(rewards, decay_rate, steps);
    console.log(result);
}

main();