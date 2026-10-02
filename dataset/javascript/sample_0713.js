function reward_decay(current, rate, threshold) {
    if (current <= threshold) {
        return current;
    }
    return reward_decay(current * rate, rate, threshold);
}

function calculate_discounted_rewards(initial, rate, threshold) {
    let rewards = [];
    while (initial > threshold) {
        rewards.push(initial);
        initial = initial * rate;
    }
    rewards.push(initial);
    return rewards;
}

function main() {
    let initial = 100;
    let rate = 0.9;
    let threshold = 10;
    let result = calculate_discounted_rewards(initial, rate, threshold);
    console.log(result);
}

main();