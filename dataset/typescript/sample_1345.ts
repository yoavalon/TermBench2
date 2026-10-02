import { randomInt } from 'crypto';

function initialize_state(): { position: number, reward: number } {
    return { position: 0, reward: 1.0 };
}

function update_state(state: { position: number, reward: number }): { position: number, reward: number } {
    state.position += randomInt(2) === 0 ? -1 : 1;
    state.reward *= 0.99;
    return state;
}

function should_terminate(state: { position: number, reward: number }): boolean {
    return Math.abs(state.position) > 10 || state.reward < 0.1;
}

function main() {
    let state = initialize_state();
    while (!should_terminate(state)) {
        state = update_state(state);
    }
    console.log(state);
}

main();