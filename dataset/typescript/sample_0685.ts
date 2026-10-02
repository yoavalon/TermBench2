function reward_decay(current_reward: number, decay_rate: number, threshold: number): number {
    if (current_reward < threshold) {
        return current_reward;
    }
    return reward_decay(current_reward * decay_rate, decay_rate, threshold);
}

function main() {
    let initial_reward = 1.0;
    let decay_rate = 0.9;
    let threshold = 0.01;
    let final_reward = reward_decay(initial_reward, decay_rate, threshold);
    console.log(final_reward);
}

main();