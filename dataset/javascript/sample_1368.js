function compute_reward_decay(initial_reward, decay_rate, time_steps) {
    let reward = initial_reward;
    for (let i = 0; i < time_steps; i++) {
        reward *= decay_rate;
    }
    return reward;
}

function simulate_data_mutation(initial_data, decay_rate, steps) {
    let mutated_data = [];
    for (let data_point of initial_data) {
        let reward = compute_reward_decay(data_point, decay_rate, steps);
        mutated_data.push(reward);
    }
    return mutated_data;
}

function main() {
    let data = [100, 200, 300, 400, 500];
    let rate = 0.95;
    let steps = 10;
    let result = simulate_data_mutation(data, rate, steps);
    console.log(result);
}

main();