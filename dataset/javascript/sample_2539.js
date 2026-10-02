function reward_decay(reward, decay_rate, steps) {
    let decayed_rewards = [];
    for (let i = 0; i < steps; i++) {
        decayed_rewards.push(reward);
        reward *= decay_rate;
    }
    return decayed_rewards;
}

function process_data(data) {
    let results = {};
    for (let idx = 0; idx < data.length; idx++) {
        results[idx] = data[idx];
    }
    return results;
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.9;
    let steps = 10;
    let rewards = reward_decay(initial_reward, decay_rate, steps);
    let output = process_data(rewards);
    for (let key in output) {
        console.log(`Step ${key}: ${output[key]}`);
    }
}

main();