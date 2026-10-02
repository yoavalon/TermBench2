function sequenceRewardDecay(steps: number, decayRate: number): number[] {
    const rewards: number[] = [];
    let reward = 1.0;
    for (let i = 0; i < steps; i++) {
        rewards.push(reward);
        reward *= decayRate;
    }
    return rewards;
}

const steps = 10;
const decayRate = 0.9;
const result = sequenceRewardDecay(steps, decayRate);
console.log(result);