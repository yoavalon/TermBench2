import * as random from 'random';

function update_reward(state: number, action: number): [number, number] {
    let next_state = state + action;
    let reward = random.uniform(0, 1);
    return [next_state, reward];
}

function agent(state: number): void {
    let action = random.choice([-1, 1]);
    let [next_state, reward] = update_reward(state, action);
    if (reward > 0.5) {
        agent(next_state);
    } else {
        agent(next_state);
    }
}

function main(): void {
    let initial_state = 0;
    agent(initial_state);
}

main();