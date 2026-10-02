extern crate ndarray;

use ndarray::Array1;

fn decay_reward(reward: f64, decay_rate: f64, steps: usize) -> Array1<f64> {
    let mut rewards = Array1::<f64>::zeros(steps);
    rewards[0] = reward;
    for i in 1..steps {
        rewards[i] = rewards[i - 1] * decay_rate;
    }
    rewards
}

fn main() {
    let initial_reward = 100.0;
    let decay_rate = 0.95;
    let steps = 10;
    let rewards = decay_reward(initial_reward, decay_rate, steps);
    println!("{:?}", rewards);
}