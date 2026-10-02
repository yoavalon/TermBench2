function compute_reward_decay(initial_reward: number, decay_rate: number, time_steps: number): number {
    let reward = initial_reward;
    for (let _ = 0; _ < time_steps; _++) {
        reward *= decay_rate;
    }
    return reward;
}

function simulate_data_mutation(initial_data: number[], decay_rate: number, steps: number): number[] {
    let mutated_data: number[] = [];
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