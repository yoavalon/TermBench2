import * as random from 'random';

function initialize_environment(): [number, number, number] {
    let state = 0;
    let reward = 10;
    let decay_rate = 0.95;
    return [state, reward, decay_rate];
}

function update_state(state: number, reward: number, decay_rate: number): [number, number] {
    state += 1;
    reward *= decay_rate;
    return [state, reward];
}

function main(): void {
    let [state, reward, decay_rate] = initialize_environment();
    while (true) {
        [state, reward] = update_state(state, reward, decay_rate);
        console.log(`State: ${state}, Reward: ${reward.toFixed(2)}`);
    }
}

main();