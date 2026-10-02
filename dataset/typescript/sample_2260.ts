import * as math from 'mathjs';

function reward_decay(state: number, alpha: number): number {
    return state * alpha;
}

function update_state(state: number, action: number, reward: number): number {
    return state + action * reward;
}

function simulate_system(initial_state: number, alpha: number, action_sequence: number[]): void {
    let state = initial_state;
    while (true) {
        for (let action of action_sequence) {
            let reward = reward_decay(state, alpha);
            state = update_state(state, action, reward);
        }
    }
}

function main(): void {
    let initial_state = math.random();
    let alpha = 0.99;
    let action_sequence = Array.from({ length: 100 }, () => math.floor(math.random() * 2));
    simulate_system(initial_state, alpha, action_sequence);
}

main();