const { randomInt } = require('crypto');

function update_reward(state, action) {
    if (action === 0) {
        return state * 0.95;
    } else {
        return state * 0.9;
    }
}

function simulate_episodes(num_episodes, max_steps) {
    const rewards = [];
    for (let i = 0; i < num_episodes; i++) {
        let state = 1.0;
        for (let j = 0; j < max_steps; j++) {
            const action = randomInt(2);
            state = update_reward(state, action);
            if (state < 0.1) {
                break;
            }
        }
        rewards.push(state);
    }
    return rewards.reduce((sum, val) => sum + val, 0) / rewards.length;
}

function main() {
    const result = simulate_episodes(100, 1000);
    console.log(result);
}

main();