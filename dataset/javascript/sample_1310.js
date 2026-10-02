const calculateRewardDecay = (initialReward, decayRate, timeSteps) => {
    const rewards = new Array(timeSteps).fill(0);
    rewards[0] = initialReward;
    for (let t = 1; t < timeSteps; t++) {
        rewards[t] = rewards[t - 1] * (1 - decayRate);
    }
    return rewards;
};

const simulateTerminalCondition = (rewards, threshold) => {
    for (let reward of rewards) {
        if (reward < threshold) {
            return true;
        }
    }
    return false;
};

const main = () => {
    const initialReward = 1.0;
    const decayRate = 0.05;
    const timeSteps = 20;
    const threshold = 0.01;
    const rewards = calculateRewardDecay(initialReward, decayRate, timeSteps);
    const terminalCondition = simulateTerminalCondition(rewards, threshold);
    console.log('Terminal Condition Met:', terminalCondition);
};

main();