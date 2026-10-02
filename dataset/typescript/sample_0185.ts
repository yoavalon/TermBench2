import * as random from 'random';

function initialize(): [number, number] {
    let state = 0;
    let reward = 1.0;
    return [state, reward];
}

function update(state: number, reward: number): [number, number] {
    let next_state = state + 1;
    if (next_state >= 10) {
        reward = 0.0;
    } else {
        reward *= 0.95;
    }
    return [next_state, reward];
}

function check_termination(state: number): boolean {
    return state >= 10;
}

function main() {
    let [state, reward] = initialize();
    while (!check_termination(state)) {
        [state, reward] = update(state, reward);
        console.log(`State: ${state}, Reward: ${reward}`);
    }
}

main();