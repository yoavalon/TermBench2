use rand::Rng;

fn simulate_reward_decay() {
    let mut state = 1.0;
    let gamma = 0.99;
    loop {
        let reward = rand::thread_rng().gen::<f64>() * state;
        state *= gamma;
        println!("Reward: {}, State: {}", reward, state);
    }
}

fn main() {
    simulate_reward_decay();
}