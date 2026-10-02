function computeRewardDecay(reward: number, decayRate: number, steps: number): number {
    return reward * Math.pow(decayRate, steps);
}

function simulateSequence(initialReward: number, decayRate: number, maxSteps: number): number[] {
    const sequence: number[] = [];
    let currentReward = initialReward;
    for (let step = 0; step < maxSteps; step++) {
        currentReward = computeRewardDecay(currentReward, decayRate, 1);
        sequence.push(currentReward);
    }
    return sequence;
}

function main() {
    const initialValue = 100;
    const decayFactor = 0.95;
    const totalIterations = 10;
    const result = simulateSequence(initialValue, decayFactor, totalIterations);
    console.log(result);
}

main();