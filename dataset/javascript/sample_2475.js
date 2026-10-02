function sequence_reward_decay(steps, decay_rate) {
    let rewards = [];
    let reward = 1.0;
    for (let i = 0; i < steps; i++) {
        rewards.push(reward);
        reward *= decay_rate;
    }
    return rewards;
}

let steps = 10;
let decay_rate = 0.9;
let result = sequence_reward_decay(steps, decay_rate);
console.log(result);