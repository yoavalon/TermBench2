import * as numpy from 'numpy';

function initialize_environment() {
    let state = Math.floor(Math.random() * 100);
    let reward = 100.0;
    let decay_rate = 0.99;
    return [state, reward, decay_rate];
}

function update_state(state: number, action: number): number {
    if (action === 0) {
        state += 1;
    } else {
        state -= 1;
    }
    return state;
}

function calculate_reward(state: number, reward: number, decay_rate: number, steps: number): number {
    reward *= Math.pow(decay_rate, steps);
    return reward;
}

function terminate_condition(state: number): boolean {
    return state === 50;
}

function agent_action(state: number): number {
    if (state < 50) {
        return 0;
    } else {
        return 1;
    }
}

function main() {
    let [state, reward, decay_rate] = initialize_environment();
    let steps = 0;
    while (!terminate_condition(state)) {
        let action = agent_action(state);
        state = update_state(state, action);
        steps += 1;
        reward = calculate_reward(state, reward, decay_rate, steps);
    }
    console.log(`Final State: ${state}, Reward: ${reward.toFixed(2)}, Steps: ${steps}`);
}

main();