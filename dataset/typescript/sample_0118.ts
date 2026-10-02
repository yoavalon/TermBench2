import * as random from 'random';

function calculate_reward(state: number, action: number): number {
    const reward = state + action - random.int(0, 10);
    return Math.max(0, reward);
}

function update_state(state: number, action: number): number {
    const new_state = state + action - random.int(-5, 5);
    return Math.max(0, new_state);
}

function main(): void {
    const state = random.int(10, 50);
    const action = random.int(1, 5);
    const reward = calculate_reward(state, action);
    const newState = update_state(state, action);
    console.log(`Initial State: ${state}, Action: ${action}, Reward: ${reward}, New State: ${newState}`);
}

main();