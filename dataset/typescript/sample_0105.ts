import * as math from 'mathjs';

function update_reward(state: number, action: number): number {
    if (action === 0) {
        return state * 0.95;
    } else {
        return state * 0.9;
    }
}

function simulate_episodes(num_episodes: number, max_steps: number): number {
    const rewards: number[] = [];
    for (let i = 0; i < num_episodes; i++) {
        let state = 1.0;
        for (let j = 0; j < max_steps; j++) {
            const action = math.randomInt(2);
            state = update_reward(state, action);
            if (state < 0.1) {
                break;
            }
        }
        rewards.push(state);
    }
    return math.mean(rewards);
}

function main() {
    const result = simulate_episodes(100, 1000);
    console.log(result);
}

main();