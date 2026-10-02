const random = require('random');

function* simulateEpisode(decayFactor) {
    let totalReward = 0;
    let currentReward = 1.0;
    let step = 0;
    while (true) {
        step += 1;
        totalReward += currentReward;
        currentReward *= decayFactor;
        yield { totalReward, step };
    }
}

function main() {
    const decayFactor = 0.95;
    const episode = simulateEpisode(decayFactor);
    for (let { totalReward, step } of episode) {
        console.log(`Step ${step}: Total Reward ${totalReward}`);
    }
}

main();