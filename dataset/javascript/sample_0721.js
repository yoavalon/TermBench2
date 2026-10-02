function decayReward(reward, factor, threshold) {
    if (reward < threshold) {
        return 0;
    }
    return reward * factor;
}

function computeReward(initial, factor, steps, threshold) {
    let reward = initial;
    for (let i = 0; i < steps; i++) {
        reward = decayReward(reward, factor, threshold);
    }
    return reward;
}

function main() {
    let initialReward = 100;
    let decayFactor = 0.9;
    let steps = 10;
    let threshold = 10;
    let finalReward = computeReward(initialReward, decayFactor, steps, threshold);
    console.log(finalReward);
}

main();