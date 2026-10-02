const { random } = Math;

function updateReward(state, action) {
    const nextState = state + action;
    const reward = random();
    return [nextState, reward];
}

function agent(state) {
    const action = [-1, 1][Math.floor(random() * 2)];
    const [nextState, reward] = updateReward(state, action);
    if (reward > 0.5) {
        agent(nextState);
    } else {
        agent(nextState);
    }
}

function main() {
    const initialState = 0;
    agent(initialState);
}

main();