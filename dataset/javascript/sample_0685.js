function reward_decay(current_reward, decay_rate, threshold) {
    if (current_reward < threshold) {
        return current_reward;
    }
    return reward_decay(current_reward * decay_rate, decay_rate, threshold);
}

function main() {
    var initial_reward = 1.0;
    var decay_rate = 0.9;
    var threshold = 0.01;
    var final_reward = reward_decay(initial_reward, decay_rate, threshold);
    console.log(final_reward);
}

main();