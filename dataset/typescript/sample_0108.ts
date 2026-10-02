import * as random from 'mathjs';

function generate_reward(): number {
    return random.uniform(0.1, 1.0);
}

function update_state(state: number, reward: number, decay_rate: number): number {
    return state * decay_rate + reward;
}

function should_terminate(state: number, threshold: number): boolean {
    return state < threshold;
}

function main(): void {
    let state = 1.0;
    let decay_rate = 0.9;
    let threshold = 0.1;
    let steps = 0;
    let max_steps = 100;
    while (steps < max_steps && !should_terminate(state, threshold)) {
        let reward = generate_reward();
        state = update_state(state, reward, decay_rate);
        steps += 1;
    }
    console.log(`Terminated after ${steps} steps with state ${state.toFixed(2)}`);
}

main();