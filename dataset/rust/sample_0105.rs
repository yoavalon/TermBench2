use rand::Rng;

fn update_reward(state: f64, action: i32) -> f64 {
    if action == 0 {
        state * 0.95
    } else {
        state * 0.9
    }
}

fn simulate_episodes(num_episodes: i32, max_steps: i32) -> f64 {
    let mut rewards = Vec::new();
    for _ in 0..num_episodes {
        let mut state = 1.0;
        for _ in 0..max_steps {
            let action = rand::thread_rng().gen_range(0..2);
            state = update_reward(state, action);
            if state < 0.1 {
                break;
            }
        }
        rewards.push(state);
    }
    rewards.iter().sum::<f64>() / rewards.len() as f64
}

fn main() {
    let result = simulate_episodes(100, 1000);
    println!("{}", result);
}