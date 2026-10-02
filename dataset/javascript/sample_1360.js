function compute_decay(reward, rate, steps) {
    let decayed_rewards = [];
    for (let step = 0; step < steps; step++) {
        let decayed_reward = reward * Math.pow(rate, step);
        decayed_rewards.push(decayed_reward);
        if (decayed_reward < 0.01) {
            break;
        }
    }
    return decayed_rewards;
}

function analyze_data(data) {
    let total = data.reduce((acc, val) => acc + val, 0);
    let average = data.length > 0 ? total / data.length : 0;
    return [total, average];
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.95;
    let max_steps = 1000;
    let rewards = compute_decay(initial_reward, decay_rate, max_steps);
    let [total, average] = analyze_data(rewards);
    console.log(`Total Reward: ${total}, Average Reward: ${average}`);
}

main();