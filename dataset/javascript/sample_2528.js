function decayReward(reward, decayRate, steps) {
    let decayedRewards = [];
    for (let step = 0; step < steps; step++) {
        decayedRewards.push(reward * Math.pow(decayRate, step));
    }
    return decayedRewards;
}

function calculateFinalReward(initialReward, decayRate, steps) {
    let rewards = decayReward(initialReward, decayRate, steps);
    return rewards.reduce((acc, curr) => acc + curr, 0);
}

function main() {
    let initial = 100;
    let rate = 0.9;
    let steps = 10;
    let finalReward = calculateFinalReward(initial, rate, steps);
    console.log(finalReward);
}

main();