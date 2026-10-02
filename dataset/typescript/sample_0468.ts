import * as random from 'random';

function* simulateEpisode(decayFactor: number) {
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
    for (let result of episode) {
        console.log(`Step ${result.step}: Total Reward ${result.totalReward}`);
    }
}

main();