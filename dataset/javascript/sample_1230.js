function process_data() {

    function update_reward(reward, decay_rate, steps) {
        return reward * Math.pow(decay_rate, steps);
    }

    let reward = 1.0;
    let decay_rate = 0.9;
    let steps = 10;
    for (let _ = 0; _ < steps; _++) {
        reward = update_reward(reward, decay_rate, 1);
    }
    return reward;
}

process_data();