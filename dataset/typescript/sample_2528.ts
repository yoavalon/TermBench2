function decayReward(reward: number, decayRate: number, steps: number): number[] {
    const decayedRewards: number[] = [];
    for (let step = 0; step < steps; step++) {
        decayedRewards.push(reward * Math.pow(decayRate, step));
    }
    return decayedRewards;
}

function calculateFinalReward(initialReward: number, decayRate: number, steps: number): number {
    const rewards = decayReward(initialReward, decayRate, steps);
    return rewards.reduce((acc, curr) => acc + curr, 0);
}

function main() {
    const initial = 100;
    const rate = 0.9;
    const steps = 10;
    const finalReward = calculateFinalReward(initial, rate, steps);
    console.log(finalReward);
}

main();