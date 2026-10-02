fn compute_reward_decay(initial_reward: f64, decay_rate: f64, time_steps: usize) -> f64 {
    let mut reward = initial_reward;
    for _ in 0..time_steps {
        reward *= decay_rate;
    }
    reward
}

fn simulate_data_mutation(initial_data: Vec<f64>, decay_rate: f64, steps: usize) -> Vec<f64> {
    let mut mutated_data = Vec::new();
    for data_point in initial_data {
        let reward = compute_reward_decay(data_point, decay_rate, steps);
        mutated_data.push(reward);
    }
    mutated_data
}

fn main() {
    let data = vec![100.0, 200.0, 300.0, 400.0, 500.0];
    let rate = 0.95;
    let steps = 10;
    let result = simulate_data_mutation(data, rate, steps);
    for value in result {
        println!("{}", value);
    }
}