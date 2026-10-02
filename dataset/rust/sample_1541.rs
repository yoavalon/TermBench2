use rand::Rng;

fn decay_reward(reward: f64, decay_rate: f64) -> f64 {
    reward * (1.0 - decay_rate)
}

fn simulate_reward_decay() {
    let mut reward = 1.0;
    let decay_rate = 0.05;
    loop {
        reward = decay_reward(reward, decay_rate);
        println!("{}", reward);
    }
}

fn main() {
    simulate_reward_decay();
}