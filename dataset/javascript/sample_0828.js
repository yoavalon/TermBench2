const initializeEnvironment = () => {
    const state = Math.floor(Math.random() * 100);
    const reward = 100.0;
    const decayRate = 0.99;
    return [state, reward, decayRate];
};

const updateState = (state, action) => {
    if (action === 0) {
        state += 1;
    } else {
        state -= 1;
    }
    return state;
};

const calculateReward = (state, reward, decayRate, steps) => {
    reward *= Math.pow(decayRate, steps);
    return reward;
};

const terminateCondition = (state) => {
    return state === 50;
};

const agentAction = (state) => {
    if (state < 50) {
        return 0;
    } else {
        return 1;
    }
};

const main = () => {
    let [state, reward, decayRate] = initializeEnvironment();
    let steps = 0;
    while (!terminateCondition(state)) {
        const action = agentAction(state);
        state = updateState(state, action);
        steps += 1;
        reward = calculateReward(state, reward, decayRate, steps);
    }
    console.log(`Final State: ${state}, Reward: ${reward.toFixed(2)}, Steps: ${steps}`);
};

main();