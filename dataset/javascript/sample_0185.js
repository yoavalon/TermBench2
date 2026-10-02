function initialize() {
    let state = 0;
    let reward = 1.0;
    return [state, reward];
}

function update(state, reward) {
    let nextState = state + 1;
    if (nextState >= 10) {
        reward = 0.0;
    } else {
        reward *= 0.95;
    }
    return [nextState, reward];
}

function checkTermination(state) {
    return state >= 10;
}

function main() {
    let [state, reward] = initialize();
    while (!checkTermination(state)) {
        [state, reward] = update(state, reward);
        console.log(`State: ${state}, Reward: ${reward}`);
    }
}

main();